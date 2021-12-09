all: main.c graph.o rvx.c zxc.c
	gcc -g main.c graph.o -llist -ltree -lstack -lqueue -o program.out -L ../lib/ -I ../include/
	gcc -g rvx.c graph.o -llist -ltree -lstack -lqueue -o rvx.out -L ../lib/ -I ../include/
	gcc -g zxc.c graph.o -llist -ltree -lstack -lqueue -o zxc.out -L ../lib/ -I ../include/
graph.o: graph.c graph.h
	gcc -g -c graph.c -llist -ltree -lstack -lqueue -o graph.o -L ../lib/ -I ../include/
clean: 
	rm -f program.out
	rm -f rvx.out
	rm -f zxc.out
	rm -f *.o