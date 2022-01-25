termtris:	termtris.o
			gcc -o termtris termtris.o -lncurses

termtris.o:	termtris.c termtris.h
			gcc -c termtris.c -lncurses

clean:
	rm -f termtris *.o