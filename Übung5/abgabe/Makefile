# Makefile
# Jakob Heigl-Auer
all: HeJ-U5-1 HeJ-U5-2

HeJ-U5-1: HeJ-U5-1.o
	gcc -Wall HeJ-U5-1.o -lm -o HeJ-U5-1

HeJ-U5-1.o: HeJ-U5-1.c
	gcc -Wall -c HeJ-U5-1.c

HeJ-U5-2: HeJ-U5-2.o
	gcc -Wall HeJ-U5-2.o -lm -o HeJ-U5-2

HeJ-U5-2.o: HeJ-U5-2.c
	gcc -Wall -c HeJ-U5-2.c

run_HeJ-U5-1:
	make HeJ-U5-1
	./HeJ-U5-1

run_HeJ-U5-2:
	make HeJ-U5-2
	./HeJ-U5-2

clean:
	rm *.o
	rm HeJ-U5-1 HeJ-U5-2

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile