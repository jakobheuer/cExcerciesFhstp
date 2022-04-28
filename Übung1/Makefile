# Makefile
# Jakob Heigl-Auer
all: HeJ-U1-1 HeJ-U1-2 HeJ-U1-3 HeJ-U1-4

HeJ-U1-1: HeJ-U1-1.o
	gcc -Wall HeJ-U1-1.o -lm -o HeJ-U1-1

HeJ-U1-1.o: HeJ-U1-1.c
	gcc -Wall -c HeJ-U1-1.c

HeJ-U1-2: HeJ-U1-2.o
	gcc -Wall HeJ-U1-2.o -lm -o HeJ-U1-2

HeJ-U1-2.o: HeJ-U1-2.c
	gcc -Wall -c HeJ-U1-2.c

HeJ-U1-3: HeJ-U1-3.o
	gcc -Wall HeJ-U1-3.o -lm -o HeJ-U1-3

HeJ-U1-3.o: HeJ-U1-3.c
	gcc -Wall -c HeJ-U1-3.c

HeJ-U1-4: HeJ-U1-4.o
	gcc -Wall HeJ-U1-4.o -lm -o HeJ-U1-4

HeJ-U1-4.o: HeJ-U1-4.c
	gcc -Wall -c HeJ-U1-4.c

clean:
	rm HeJ-U1-1 HeJ-U1-2 HeJ-U1-3 HeJ-U1-4
	rm *.o

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile