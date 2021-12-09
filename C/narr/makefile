all: main.c narr.o
	gcc -g main.c narr.o -o program.out
narr.o: narr.c narr.h
	gcc -g -c narr.c -o narr.o
clean: 
	rm -f program.out
	rm -f *.o