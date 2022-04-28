# Makefile
# Jakob Heigl-Auer
all: HeJ-U2-1 HeJ-U2-2 HeJ-U2-3 HeJ-U2-4

HeJ-U2-1: HeJ-U2-1.o
	gcc -Wall HeJ-U2-1.o -lm -o HeJ-U2-1

HeJ-U2-1.o: HeJ-U2-1.c
	gcc -Wall -c HeJ-U2-1.c

HeJ-U2-2: HeJ-U2-2.o
	gcc -Wall HeJ-U2-2.o -lm -o HeJ-U2-2

HeJ-U2-2.o: HeJ-U2-2.c
	gcc -Wall -c HeJ-U2-2.c

HeJ-U2-3: HeJ-U2-3.o
	gcc -Wall HeJ-U2-3.o -lm -o HeJ-U2-3

HeJ-U2-3.o: HeJ-U2-3.c
	gcc -Wall -c HeJ-U2-3.c

HeJ-U2-4.o: HeJ-U2-4.c
	gcc -Wall -c HeJ-U2-4.c

HeJ-U2-4: HeJ-U2-4.o
	gcc -Wall HeJ-U2-4.o -lm -o HeJ-U2-4



run_HeJ-U2-1:
	make HeJ-U2-1
	./HeJ-U2-1

run_HeJ-U2-2:
	make HeJ-U2-2
	./HeJ-U2-2

run_HeJ-U2-3:
	make HeJ-U2-3
	./HeJ-U2-3

run_HeJ-U2-4:
	make HeJ-U2-4
	./HeJ-U2-4

clean:
	rm HeJ-U2-1 HeJ-U2-2 HeJ-U2-3 HeJ-U2-4
	rm *.o

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile