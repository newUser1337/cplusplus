all: LinkedList.o ArrayList.o main.cpp
	g++ -g main.cpp -o program.out

LinkedList.o: ../linkedlist/LinkedList.h ../linkedlist/LinkedList.cpp ../iterable/Iterable.h
	g++ -g -c ../linkedlist/LinkedList.cpp -o LinkedList.o

ArrayList.o: ../arraylist/ArrayList.h ../arraylist/ArrayList.cpp ../iterable/Iterable.h
	g++ -g -c ../arraylist/ArrayList.cpp -o ArrayList.o