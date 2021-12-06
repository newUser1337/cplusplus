all: main.c fenw.o
	gcc -g main.c fenw.o -o program.out
fenw.o: fenw.c fenw.h
	gcc -c -g fenw.c -o fenw.o
clean:
	rm -f program.out
	rm -f *.o