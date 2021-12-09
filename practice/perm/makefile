all: main.cpp Perm.o
	g++ -g main.cpp Perm.o -o program.out
Perm.o: Perm.cpp Perm.h
	g++ -g -c Perm.cpp -o Perm.o
clean:
	rm -f program.out
	rm -f *.o