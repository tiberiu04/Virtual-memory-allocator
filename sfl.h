#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <ctype.h>

typedef struct dll_node_t {
	void *data;
	struct dll_node_t *prev, *next;
} dll_node_t;

typedef struct list_t {
	dll_node_t *head, *tail;
	unsigned int block_size;
	unsigned int data_size;
	unsigned int size;
} list_t;

typedef struct {
	int heap_base;
	size_t size;
	list_t **segregated_lists;
	int num_lists;
} heap_t;

typedef struct mem_block {
	void *start_address;
	int size;
	struct mem_block *prev, *next;
} mem_block;

typedef struct occupied_mem_block {
	struct mem_block *head, *tail;
	unsigned int size;
	unsigned int data_size;
	void *adresses;
} occupied_mem_block;

occupied_mem_block
*create_occupied_mem_block(heap_t *heap, int bytes_per_list);
list_t*
dll_create(unsigned int data_size);
dll_node_t*
dll_get_nth_node(list_t *list, unsigned int n);
dll_node_t*
dll_remove_nth_node(list_t *list, unsigned int n);
void
dll_add_nth_node(list_t *list, unsigned int n, const void *data);
unsigned int
dll_get_size(list_t *list);
void dll_free(list_t **pp_list);
void
dll_print_addresses(list_t *list);

heap_t *init_heap(int heap_base, int num_lists, int bytes_per_list);
void
add_nth_mem_block(occupied_mem_block *list,
				  const void *address, int bytes, int n);
int find(heap_t *heap, int bytes);
void delete_null_lists(heap_t *heap);
void
insert_address_in_allocated_blocks(list_t *list, int bytes,
								   occupied_mem_block *blocks);
void add_in_list(list_t *list, int address);
int condition(int address, mem_block *temp);
int condition_list(int address, dll_node_t *temp);
int return_position_list(int address, dll_node_t *temp);
void
my_malloc(heap_t *heap,  int bytes, occupied_mem_block *blocks,
		  int *malloc_calls, int *frag);
void remove_nth_mem_block(occupied_mem_block *list, int n);
void freetype0(heap_t *heap, occupied_mem_block *blocks, int address);
void add_list(heap_t *heap, int bytes, int address);
int is_start(int address, int bytes_per_list, int num_lists);
void freetype1(int address, heap_t *heap, occupied_mem_block *blocks,
			   int *frag, int bytes_per_list, int num_lists);
void
my_free(heap_t **heap, int address, occupied_mem_block *blocks, int type,
		int *nr_free, int *frag, int bytes_per_list, int num_lists);
void
dump_memory(heap_t *heap, occupied_mem_block *blocks, int malloc_calls,
			int free_calls, int frag, int total_memory);

void free_occupied_mem_blocks(occupied_mem_block **blocks);

void
destroy_heap(heap_t **heap, occupied_mem_block **blocks);

void
write(heap_t *heap, int address, char *data, int nr_bytes,
	  occupied_mem_block *mem_blocks, int malloc_calls, int free_calls,
	  int frag, int total_memory);
void
read(heap_t *heap, int address, int nr_bytes, occupied_mem_block *mem_blocks,
	 int malloc_calls, int free_calls, int frag, int total_memory);

void det_parameters(char *text, char *data, int *size);
