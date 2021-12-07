all: main.c lib
	gcc -g main.c queue.o -o program.out
lib: queue.o
	ar cr ../lib/libqueue.a queue.o
	cp queue.h ../include/queue.h
queue.o: queue.c queue.h
	gcc -g -c queue.c -o queue.o
clean: 
	rm -f *.o
	rm -f program.out