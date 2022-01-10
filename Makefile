termtris:	termtris.o
			gcc -o termtris termtris.o

termtris.o:	termtris.c termtris.h
			gcc -c termtris.c

clean:
	rm -f termtris *.o