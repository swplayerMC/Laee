CC = gcc

Lae: main.o functions.o help.o
	$(CC) main.o functions.o help.o -o ../bin/lae

main.o: main.c
	$(CC) -c main.c -o main.o

functions.o: functions.c functions.h
	$(CC) -c functions.c -o functions.o

help.o: help.c help.h
	$(CC) -c help.c -o help.o

clean:
	rf -rf *.o
