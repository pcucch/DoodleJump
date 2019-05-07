# Definitions for constants
CC=g++
CFLAGS = -I. 

# This will create your final output using .o compiled files
make: main.o functions.o doodlerfunctions.o enemyfunctions.o platformfunctions.o bulletfunctions.o
	$(CC) $(CFLAGS) -o MoodleJump main.o functions.o doodlerfunctions.o enemyfunctions.o platformfunctions.o bulletfunctions.o -lncurses

main.o: main.cpp doodlejump.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o 

doodlerfunctions.o: doodlerfunctions.cpp 
	$(CC) $(CFLAGS) -c doodlerfunctions.cpp -o doodlerfunctions.o

enemyfunctions.o: enemyfunctions.cpp 
	$(CC) $(CFLAGS) -c enemyfunctions.cpp -o enemyfunctions.o 

platformfunctions.o: platformfunctions.cpp
	$(CC) $(CFLAGS) -c platformfunctions.cpp -o platformfunctions.o

bulletfunctions.o: bulletfunctions.cpp 
	$(CC) $(CFLAGS) -c bulletfunctions.cpp -o bulletfunctions.o 

# This will clean or remove compiled files so you can start fresh
