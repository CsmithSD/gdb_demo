SOURCE = main_entry_exit.cpp main_leak.cpp functions.cpp io.cpp linkedList.cpp\
         main_trace.cpp longRun.cpp

CXXFLAGS = -Wall -std=c++11
CFLAGS = $(CXXFLAGS)

GCC = g++

all: main_trace main_entry_exit theBug theOtherBug main_leak longRun

longRun: longRun.o
	g++ -o $@ $(CXXFLAGS) $^

theBug: theBug.o
	g++ -o $@ $(CXXFLAGS) $^

main_trace: main_trace.o
	g++ -o $@ $(CXXFLAGS) $^

main_entry_exit: main_entry_exit.o
	g++ -o $@ $(CXXFLAGS) $^

theOtherBug: theOtherBug.o
	g++ -o $@ $(CXXFLAGS) $^

main_leak: main_leak.o io.o functions.o linkedList.o
	g++ -o $@ $(CXXFLAGS) $^

debug: CXXFLAGS += -DDEBUG -g
debug: all

clean:
	rm -rf  theBug *.o main_leak theOtherBug out.xml main_entry_exit *.d\
            main_trace longRun

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; /usr/bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

