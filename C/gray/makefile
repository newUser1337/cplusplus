all: gray.o main.c
	gcc -g main.c gray.o -o program.out
gray.o: gray.c gray.h
	gcc -c -g gray.c -o gray.o
clean:
	rm -f *.o
	rm -f program.out