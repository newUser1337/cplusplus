all: ArrayList.o main.cpp
	g++ -g main.cpp ArrayList.o -o program.out

ArrayList.o: ArrayList.h ArrayList.cpp ../iterable/Iterable.h
	g++ -g -c ArrayList.cpp -o ArrayList.o

clean: 
	rm -f *.o
	rm -f program.out