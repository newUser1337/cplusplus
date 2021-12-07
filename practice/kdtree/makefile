all: main.cpp Kdtree.o
	g++ -g main.cpp Kdtree.o -o program.out
Kdtree.o: Kdtree.h Kdtree.cpp
	g++ -g -c Kdtree.cpp -o Kdtree.o
clean:
	rm -f program.out
	rm -f *.o