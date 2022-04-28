# Makefile
# Jakob Heigl-Auer
all: HeJ-U11-1 HeJ-U11-2 HeJ-U11-3

HeJ-U11-1: HeJ-U11-1.o
	gcc -Wall HeJ-U11-1.o -o HeJ-U11-1

HeJ-U11-1.o: HeJ-U11-1.c
	gcc -Wall -c HeJ-U11-1.c

HeJ-U11-2: HeJ-U11-2.o
	gcc -Wall HeJ-U11-2.o -o HeJ-U11-2

HeJ-U11-2.o: HeJ-U11-2.c
	gcc -Wall -c HeJ-U11-2.c

HeJ-U11-3: HeJ-U11-3.o
	gcc -Wall HeJ-U11-3.o -o HeJ-U11-3

HeJ-U11-3.o: HeJ-U11-3.c
	gcc -Wall -c HeJ-U11-3.c

run_HeJ-U11-1:
	make HeJ-U11-1
	./HeJ-U11-1

run_HeJ-U11-2:
	make HeJ-U11-2
	./HeJ-U11-2

run_HeJ-U11-3:
	make HeJ-U11-3
	./HeJ-U11-3

clean:
	rm *.o
	rm HeJ-U11-1 HeJ-U11-2 HeJ-U11-3

abgabe:
	tar cfz abgabe.tar.gz *.c Makefile