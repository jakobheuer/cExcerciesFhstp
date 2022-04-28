# Makefile
# Jakob Heigl-Auer
all: HeJ-U8-1

HeJ-U8-1: HeJ-U8-1.o
	gcc -Wall HeJ-U8-1.o -lm -o HeJ-U8-1

HeJ-U8-1.o: HeJ-U8-1.c
	gcc -Wall -c HeJ-U8-1.c

run_HeJ-U8-1:
	make HeJ-U8-1
	./HeJ-U8-1


clean:
	rm *.o
	rm HeJ-U8-1

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile