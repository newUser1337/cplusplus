all: main.cpp Disj.o
	g++ -g main.cpp Disj.o -o program.out
Disj.o: Disj.h Disj.cpp
	g++ -g -c Disj.cpp -o Disj.o
clean: 
	rm -f program.out
	rm -f *.o