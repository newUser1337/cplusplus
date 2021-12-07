all: main.c kdtree.o
	gcc -g main.c kdtree.o -llist -o program.out -L ../lib/ -I ../include/
kdtree.o: kdtree.c kdtree.h
	gcc -g -c kdtree.c -llist -o kdtree.o -L ../lib/ -I ../include/
clean: 
	rm -f program.out
	rm -f *.o