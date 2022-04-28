# Makefile
# Jakob Heigl-Auer
all: HeJ-U9-1

HeJ-U9-1: HeJ-U9-1.o HeJ_Fence_List.o
	gcc -Wall HeJ-U9-1.o HeJ_Fence_List.o -lm -o HeJ-U9-1

HeJ-U9-1.o: HeJ-U9-1.c HeJ_Fence_List.h
	gcc -Wall -c HeJ-U9-1.c

HeJ_Fence_List.o: HeJ_Fence_List.c HeJ_Fence_List.h
	gcc -Wall -c HeJ_Fence_List.c

run_HeJ-U9-1:
	make HeJ-U9-1
	./HeJ-U9-1

clean:
	rm *.o
	rm HeJ-U9-1

abgabe:
	tar cfz abgabe.tar.gz *.c *.h Makefile