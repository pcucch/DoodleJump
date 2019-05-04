# Definitions for constants
CC=g++
CFLAGS = -I. 

# This will create your final output using .o compiled files
make: doodlejump.o hierarchy.o
	$(CC) $(CFLAGS) -o main doodlejump.o hierarchy.o

doodlejump.o: doodlejump.cpp doodlejump.h
	$(CC) $(CFLAGS) -c doodlejump.cpp -o doodlejump.o

hierarchy.o: hierarchy.cpp
	$(CC) $(CFLAGS) -c hierarchy.cpp -o hierarchy.o

# This will clean or remove compiled files so you can start fresh
