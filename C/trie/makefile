all: trie.o main.c
	gcc -g main.c trie.o -llist -o program.out -L ../lib/ -I ../include/ 
trie.o: trie.c trie.h 
	gcc -c -g trie.c -llist -o trie.o -L ../lib/ -I ../include/ 
clean:
	rm -f *.o
	rm -f program.out