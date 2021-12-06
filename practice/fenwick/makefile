all: Fenwick.o main.cpp
	g++ -g main.cpp Fenwick.o -o program.out
Fenwick.o: Fenwick.h Fenwick.cpp
	g++ -c -g Fenwick.cpp -o Fenwick.o
clean:
	rm -f *.o
	rm -f program.out