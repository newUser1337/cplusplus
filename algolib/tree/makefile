all: Tree.o main.cpp 
	g++ -g main.cpp Tree.o -o program.out

Tree.o: Tree.h Tree.cpp ../iterable/Iterable.h
	g++ -g -c Tree.cpp -o Tree.o

clean: 
	rm -f *.o
	rm -f program.out