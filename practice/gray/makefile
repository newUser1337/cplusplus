all: Gray.o main.cpp
	g++ -g main.cpp Gray.o -o program.out
Gray.o: Gray.cpp Gray.h
	g++ -c -g Gray.cpp -o Gray.o
clean:
	rm -f *.o
	rm -f program.out