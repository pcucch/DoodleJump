# Definitions for constants
CC=g++
CFLAGS = -I. 

# This will create your final output using .o compiled files
make: main.o functions.o
    $(CC) $(CFLAGS) -o main main.o functions.o -lncurses

main.o: main.cpp doodlejump.h
    $(CC) $(CFLAGS) -c main.cpp -o main.o -lncurses

functions.o: functions.cpp doodlejump.h
    $(CC) $(CFLAGS) -c functions.cpp -o functions.o -lncurses

# This will clean or remove compiled files so you can start fresh
