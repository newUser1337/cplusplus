all: main.c graph.o
	gcc -g main.c graph.o -llist -ltree -lstack -lqueue -o program.out -L ../lib/ -I ../include/
graph.o: graph.c graph.h
	gcc -g -c graph.c -llist -ltree -lstack -lqueue -o graph.o -L ../lib/ -I ../include/
clean: 
	rm -f program.out
	rm -f *.o