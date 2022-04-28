# Philipp Osanger
# erstellen der Executable

all: OsP-U10-1

# Uebungsprogramme Executables
OsP-U10-1: OsP-U10-1.o OsP_ValueTree.o
	gcc -Wall OsP-U10-1.o OsP_ValueTree.o -o OsP-U10-1

# Uebungsprogramme O-Files
OsP-U10-1.o: OsP-U10-1.c OsP_ValueTree.h
	gcc -Wall -c OsP-U10-1.c

OsP_ValueTree.o: OsP_ValueTree.c OsP_ValueTree.h
	gcc -Wall -c OsP_ValueTree.c

# Clean und Abgabe
clean:
	rm -f OsP-U10-1
	rm -f *.o *.gz

abgabe:
	make clean
	tar cvfz abgabe.tar.gz *.c *.h Makefile
