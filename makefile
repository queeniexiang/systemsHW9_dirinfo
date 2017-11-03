all: dirinfo.o
	gcc -o test dirinfo.o

dirinfo.o: dirinfo.c
	gcc -c dirinfo.c

run: all
	./test
