all: main.cpp Trie.o
	g++ -g main.cpp Trie.o -o program.out
Trie.o: Trie.cpp Trie.h
	g++ -g -c Trie.cpp -o Trie.o
clean: 
	rm -f program.out
	rm -f *.o