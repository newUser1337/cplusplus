all: tree.o main.c
	gcc -g main.c tree.o -o program.out
tree.o: tree.c tree.h
	gcc -c -g tree.c -o tree.o
clean:
	rm -f *.o
	rm -f program.out