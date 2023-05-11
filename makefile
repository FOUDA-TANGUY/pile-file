CC=gcc
EXE=programme
DFLAGS= 
LFLAGS= -I include
executable: *.o
	$(CC) obj/*.o -o bin/$(EXE) $(DFLAGS)

build:
	$(CC) obj/*.o -o bin/$(EXE) $(DFLAGS)

*.o: main.o element.o file.o pile.o arbre.o

main.o:
	$(CC) -o obj/main.o -c src/main.c $(LFLAGS)

pile.o:
	$(CC) -o obj/pile.o -c src/pile.c $(LFLAGS)

file.o:
	$(CC) -o obj/file.o -c src/file.c $(LFLAGS)

arbre.o:
	$(CC) -o obj/arbre.o -c src/arbre.c $(LFLAGS)

element.o:
	$(CC) -o obj/element.o -c src/element.c $(LFLAGS)

run:
	bin/$(EXE)

clean:
	rm -f obj/*.o
	rm -f bin/$(EXE)