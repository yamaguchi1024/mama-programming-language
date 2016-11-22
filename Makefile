.PHONY: all
all: mama bf2mama
mama: mama.c
	gcc -o mama mama.c
bf2mama: bf2mama.c
	gcc -o bf2mama bf2mama.c
