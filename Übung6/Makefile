# Makefile
# Jakob Heigl-Auer
all: HeJ-U6-1

HeJ-U6-1: HeJ-U6-1.o
	gcc -Wall HeJ-U6-1.o -lm -o HeJ-U6-1

HeJ-U6-1.o: HeJ-U6-1.c
	gcc -Wall -c HeJ-U6-1.c

run_HeJ-U6-1:
	make HeJ-U6-1
	./HeJ-U6-1


clean:
	rm *.o
	rm HeJ-U5-1

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile