all: list.o main.c
	gcc -g main.c list.o -lm -o program.out
list.o: list.c list.h
	gcc -c -g list.c -o list.o
clean:
	rm -f *.o
	rm -f program.out