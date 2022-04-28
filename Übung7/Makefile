# Makefile
# Jakob Heigl-Auer
all: HeJ-U7-1

HeJ-U7-1: HeJ-U7-1.o
	gcc -Wall HeJ-U7-1.o -lm -o HeJ-U7-1

HeJ-U7-1.o: HeJ-U7-1.c
	gcc -Wall -c HeJ-U7-1.c

run_HeJ-U7-1:
	make HeJ-U7-1
	./HeJ-U7-1


clean:
	rm *.o
	rm HeJ-U5-1

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile