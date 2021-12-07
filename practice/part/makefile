all: Part.o main.cpp
	g++ -g main.cpp Part.o -o program.out 
Part.o: Part.cpp Part.h 
	g++ -c -g Part.cpp  -o Part.o 
clean:
	rm -f *.o
	rm -f program.out