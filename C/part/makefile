all: part.o main.c
	gcc -g main.c part.o -o program.out 
part.o: part.c part.h 
	gcc -c -g part.c  -o part.o 
clean:
	rm -f *.o
	rm -f program.out