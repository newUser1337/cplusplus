all:main.cpp rvx.cpp zxc.cpp Graph.o
	g++ -g main.cpp Graph.o -o program.out
	g++ -g rvx.cpp Graph.o -o rvx.out
	g++ -g zxc.cpp Graph.o -o zxc.out
Graph.o: Graph.cpp Graph.h
	g++ -g -c Graph.cpp -o Graph.o 
clean:
	rm -f program.out
	rm -f rvx.out
	rm -f zxc.out
	rm -f *.o