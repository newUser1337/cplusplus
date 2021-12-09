all: main.cpp Segment.o
	g++ -g main.cpp Segment.o -o program.out
Segment.o: Segment.cpp Segment.h
	g++ -g -c Segment.cpp -o Segment.o
clean: 
	rm -f program.out
	rm -f *.o