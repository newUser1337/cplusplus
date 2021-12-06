all: main.c heap.o
	gcc -g main.c heap.o -o program.out
heap.o: heap.c heap.h
	gcc -c -g heap.c -o heap.o
clean:
	rm -f program.out
	rm -f *.o