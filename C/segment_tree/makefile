all: segment.o main.c
	gcc -g main.c segment.o -o program.out

segment.o: segment.c segment.h
	gcc -c -g segment.c -o segment.o

clean:
	rm -f *.o
	rm -f program.out