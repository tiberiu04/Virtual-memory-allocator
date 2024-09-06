#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <ctype.h>
#include "sfl.h"
int main(void)
{
	heap_t *heap = NULL;
	occupied_mem_block *blocks = NULL;
	int type, free_calls = 0, malloc_calls = 0, frag = 0, total_memory;
	int num_lists, bytes_per_list, size, address;
	char data[600] = "", buffer[600] = "", c, command[600];

	do {
		scanf("%s", command);
		if (strcmp(command, "INIT_HEAP") == 0) {
			scanf("%x %d %d %d", &address, &num_lists, &bytes_per_list, &type);
			heap = init_heap(address, num_lists, bytes_per_list);
			blocks = create_occupied_mem_block(heap, bytes_per_list);
			total_memory = num_lists * bytes_per_list;
		} else if (strcmp(command, "MALLOC") == 0) {
			scanf("%u", &size);
			my_malloc(heap, size, blocks, &malloc_calls, &frag);
		} else if (strcmp(command, "FREE") == 0) {
			scanf("%x", &address);
			int a = bytes_per_list;
			int b = num_lists;
			my_free(&heap, address, blocks, type, &free_calls, &frag, a, b);
		} else if (strcmp(command, "READ") == 0) {
			scanf("%x %d", &address, &size);
			read(heap, address, size, blocks, malloc_calls,
				 free_calls, frag, total_memory);
		} else if (strcmp(command, "WRITE") == 0) {
			scanf("%x", &address);
			scanf("%c", &c);//I read the space
			fgets(buffer, 600, stdin);
			buffer[strlen(buffer)] = '\0';
			det_parameters(buffer, data, &size);//Obtaining the string
			write(heap, address, data, size, blocks, malloc_calls,
				  free_calls, frag, total_memory);
		} else if (strcmp(command, "DUMP_MEMORY") == 0) {
			dump_memory(heap, blocks, malloc_calls, free_calls,
						frag, total_memory);
		}
	} while (strcmp(command, "DESTROY_HEAP") != 0);

	destroy_heap(&heap, &blocks);
	return 0;
}
