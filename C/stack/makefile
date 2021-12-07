lib: stack.o
	ar cr ../lib/libstack.a stack.o
	cp stack.h ../include/stack.h
stack.o: stack.c stack.h
	gcc -c -g stack.c -o stack.o
clean:
	rm -f *.o