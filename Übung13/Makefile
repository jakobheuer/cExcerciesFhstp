# Makefile
# Jakob Heigl-Auer
all: HeJ-U13-1 HeJ-U13-2

HeJ-U13-1: HeJ-U13-1.o
	gcc -Wall HeJ-U13-1.o -o HeJ-U13-1

HeJ-U13-1.o: HeJ-U13-1.c
	gcc -Wall -c HeJ-U13-1.c

HeJ-U13-2: HeJ-U13-2.o
	gcc -Wall HeJ-U13-2.o -o HeJ-U13-2

HeJ-U13-2.o: HeJ-U13-2.c
	gcc -Wall -c HeJ-U13-2.c

run_HeJ-U13-1:
	make HeJ-U13-1
	./HeJ-U13-1

run_HeJ-U13-2:
	make HeJ-U13-2
	./HeJ-U13-2

clean:
	rm *.o
	rm HeJ-U13-1 HeJ-U13-2

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile