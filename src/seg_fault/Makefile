#GNU C/C++ compiler and linker:
CC = gcc
CXX = g++
LINK = g++
    
CFLAGS = -O -Wall
CXXFLAGS = -O -Wall

all: seg

seg: seg.c
	   $(LINK) $(DEBUG) -o $@ $^

debug: DEBUG = -g

debug: seg

clean:
	rm -f *.o *~ seg	
