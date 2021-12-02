all: Hash.o main.cpp rvz.cpp
	g++ -g main.cpp Hash.o -o program.out
	g++ -g rvz.cpp Hash.o -o rvz.out

Hash.o: Hash.h Hash.cpp ../iterable/Iterable.h
	g++ -g -c Hash.cpp -o Hash.o

clean: 
	rm -f *.o
	rm -f program.out