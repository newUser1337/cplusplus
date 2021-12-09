all: main.cpp Graph.o rvx.cpp
	g++ -g main.cpp Graph.o -o program.out
	g++ -g rvx.cpp Graph.o -o rvx.out
Graph.o: Graph.cpp Graph.h
	g++ -g -c Graph.cpp -o Graph.o
clean:
	rm -f program.out
	rm -f *.o
	rm -f rvx.out