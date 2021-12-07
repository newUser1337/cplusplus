all: main.c disj.o
	gcc -g main.c disj.o -ltree -o program.out -L ../lib/ -I ../include/
disj.o: disj.c disj.h
	gcc -g -c disj.c -ltree -o disj.o -L ../lib/ -I ../include/ 

clean: 
	rm -f *.o
	rm -f program.out