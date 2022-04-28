# Makefile
# Jakob Heigl-Auer
all: HeJ-U10-1

HeJ-U10-1: HeJ-U10-1.o HeJ_ValueTree.o
	gcc -Wall HeJ-U10-1.o HeJ_ValueTree.o -lm -o HeJ-U10-1

HeJ-U10-1.o: HeJ-U10-1.c HeJ_ValueTree.h
	gcc -Wall -c HeJ-U10-1.c

HeJ_ValueTree.o: HeJ_ValueTree.c HeJ_ValueTree.h
	gcc -Wall -c HeJ_ValueTree.c

run_HeJ-U10-1:
	make HeJ-U10-1
	./HeJ-U10-1

clean:
	rm *.o
	rm HeJ-U10-1

abgabe:
	tar cfz abgabe.tar.gz *.c *.h Makefile