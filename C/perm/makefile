all: main.c perm.o
	gcc -g main.c perm.o -o program.out
perm.o: perm.c perm.h
	gcc -g -c perm.c -o perm.o
clean:
	rm -f program.out
	rm -f *.o