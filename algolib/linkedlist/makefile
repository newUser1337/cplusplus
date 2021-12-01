all: LinkedList.o main.cpp
	g++ -g main.cpp LinkedList.o -o program.out

LinkedList.o: LinkedList.h LinkedList.cpp ../iterable/Iterable.h
	g++ -g -c LinkedList.cpp -o LinkedList.o

clean: 
	rm -f *.o
	rm -f program.out