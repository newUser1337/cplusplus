all: Sparce.o main.cpp
	g++ -g main.cpp Sparce.o -o program.out
Sparce.o: Sparce.h Sparce.cpp
	g++ -c -g Sparce.cpp -o Sparce.o
clean:
	rm -f *.o
	rm -f program.out