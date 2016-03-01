#GNU C/C++ compiler and linker:
CC = gcc
CXX = g++
LINK = g++
    
CFLAGS = -std=c99 -O -Wall
CXXFLAGS = -O -Wall

all: read_string

read_string: read_string.c
	   $(CC) $(DEBUG) $(CFLAGS) -o $@ $^

debug: DEBUG = -g

debug: read_string

clean:
	rm -f *.o *~ read_string	
