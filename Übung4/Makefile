# Makefile
# Jakob Heigl-Auer
all: HeJ-U4-1 HeJ-U4-2 HeJ-U4-3

HeJ-U4-1: HeJ-U4-1.o
	gcc -Wall HeJ-U4-1.o -lm -o HeJ-U4-1

HeJ-U4-1.o: HeJ-U4-1.c
	gcc -Wall -c HeJ-U4-1.c

HeJ-U4-2: HeJ-U4-2.o
	gcc -Wall HeJ-U4-2.o -lm -o HeJ-U4-2

HeJ-U4-2.o: HeJ-U4-2.c
	gcc -Wall -c HeJ-U4-2.c

HeJ-U4-3: HeJ-U4-3.o
	gcc -Wall HeJ-U4-3.o -lm -o HeJ-U4-3

HeJ-U4-3.o: HeJ-U4-3.c
	gcc -Wall -c HeJ-U4-3.c

run_HeJ-U4-1:
	make HeJ-U4-1
	./HeJ-U4-1

run_HeJ-U4-2:
	make HeJ-U4-2
	./HeJ-U4-2

run_HeJ-U4-3:
	make HeJ-U4-3
	./HeJ-U4-3

clean:
	rm *.o
	rm HeJ-U4-1 HeJ-U4-2 HeJ-U4-3

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile