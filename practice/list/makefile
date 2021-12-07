all: lib main.cpp
	g++ -g main.cpp List.o -o program.out
lib: List.o
	ar cr ../lib/liblist.a List.o
	cp List.h ../include/List.h
List.o: List.h List.cpp
	g++ -g -c List.cpp -o List.o
clean:
	rm -f program.out
	rm -f *.o