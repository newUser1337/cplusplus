all: main.cpp Hash.o
	g++ -g main.cpp Hash.o -o program.out
Hash.o: Hash.cpp Hash.h
	g++ -g -c Hash.cpp -o Hash.o
clean:
	rm -f program.out
	rm -f *.o