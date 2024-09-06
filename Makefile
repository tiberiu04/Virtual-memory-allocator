CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS = sfl

build: $(TARGETS)

sfl: main.c
	$(CC) $(CFLAGS) -g -o sfl sfl.c main.c

pack:
	zip -FSr 311CA_GutanuTiberiuMihnea_Tema1.zip README README.md Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean