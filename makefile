# Definitions for constants
CC=g++
CFLAGS = -I. 

# This will create your final output using .o compiled files
make: doodlejump.o functions.o
	$(CC) $(CFLAGS) -o main doodlejump.o functions.o -lncurses

doodlejump.o: main.cpp doodlejump.h
	$(CC) $(CFLAGS) -c main.cpp -o doodlejump.o -lncurses

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o

# This will clean or remove compiled files so you can start fresh
