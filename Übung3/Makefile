# Makefile
# Jakob Heigl-Auer
all: HeJ-U3-1 HeJ-U3-2 HeJ-U3-3 HeJ-U3-4 HeJ-U3-5

HeJ-U3-1: HeJ-U3-1.o
	gcc -Wall HeJ-U3-1.o -lm -o HeJ-U3-1

HeJ-U3-1.o: HeJ-U3-1.c
	gcc -Wall -c HeJ-U3-1.c

HeJ-U3-2: HeJ-U3-2.o
	gcc -Wall HeJ-U3-2.o -lm -o HeJ-U3-2

HeJ-U3-2.o: HeJ-U3-2.c
	gcc -Wall -c HeJ-U3-2.c

HeJ-U3-3: HeJ-U3-3.o HeJ-RiverFkt.o
	gcc -Wall HeJ-U3-3.o HeJ-RiverFkt.o -lm -o HeJ-U3-3

HeJ-U3-3.o: HeJ-U3-3.c HeJ-RiverFkt.h
	gcc -Wall -c HeJ-U3-3.c

HeJ-RiverFkt.o: HeJ-RiverFkt.c HeJ-RiverFkt.h
	gcc -Wall -c HeJ-RiverFkt.c

HeJ-U3-4: HeJ-U3-4.o HeJ-RiverFkt.o
	gcc -Wall HeJ-U3-4.o HeJ-RiverFkt.o -lm -o HeJ-U3-4

HeJ-U3-4.o: HeJ-U3-4.c HeJ-RiverFkt.h
	gcc -Wall -c HeJ-U3-4.c

HeJ-U3-5: HeJ-U3-5.c
	gcc -Wall HeJ-U3-5.c -o HeJ-U5_64
	gcc -Wall HeJ-U3-5.c -m32 -o HeJ-U5_32


run_HeJ-U3-1:
	make HeJ-U3-1
	./HeJ-U3-1

run_HeJ-U3-2:
	make HeJ-U3-2
	./HeJ-U3-2

run_HeJ-U3-3:
	make HeJ-U3-3
	./HeJ-U3-3

run_HeJ-U3-4:
	make HeJ-U3-4
	./HeJ-U3-4

run_HeJ-U3-5_64:
	make HeJ-U3-5
	./HeJ-U5_64

run_HeJ-U3-5_32:
	make HeJ-U3-5
	./HeJ-U5_32

clean:
	rm *.o
	rm HeJ-U3-1 HeJ-U3-2 HeJ-U3-3 HeJ-U3-4 HeJ-U5_64 HeJ-U5_32

abgabe:
	tar cfz abgabe.tar.gz *.c *.h Makefile