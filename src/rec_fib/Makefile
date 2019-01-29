#GNU C/C++ compiler and linker:
CC = gcc
CXX = g++
LINK = g++
    
CFLAGS = -O -Wall
CXXFLAGS = -O -Wall

all: fib

fib: fib.cpp
	   $(LINK) $(DEBUG) -o $@ $^

debug: DEBUG = -g

debug: fib

clean:
	rm -f *.o *~ fib	
