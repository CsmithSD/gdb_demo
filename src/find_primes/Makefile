#--------------------------------------------------------------------
CC = gcc
LIBS =
FLAGS = -Wall -fopenmp -lm
EXECS = SatSource prime
Sources = SatSource.c find_primes.c

all: $(Sources) $(EXECS)


SatSource: SatSource.c
		$(CC) $(DEBUG) $(FLAGS) -o $@ $? $(LIBS)

prime: find_primes.c
		$(CC) $(DEBUG) $(FLAGS) -o $@ $? $(LIBS)

debug: DEBUG = -g
debug: prime SatSource
clean:
	$(RM) $(EXECS)
#--------------------------------------------------------------------
