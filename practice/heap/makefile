all: Heap.o main.cpp
	g++ -g main.cpp Heap.o -o program.out
Heap.o: Heap.h Heap.cpp
	g++ -c -g Heap.cpp -o Heap.o
clean:
	rm -f *.o
	rm -f program.out