EXENAME = run

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

.PHONY: all test clean

all : $(EXENAME)

$(EXENAME): run.o DNA.o People.o
	$(LD) run.o DNA.o People.o $(LDFLAGS) -o $(EXENAME)

run.o : run.cpp DNA.h People.h
	$(CXX) $(CXXFLAGS) run.cpp

DNA.o : run.cpp DNA.h
	$(CXX) $(CXXFLAGS) DNA.cpp

People.o : People.cpp DNA.h run.cpp DNA.o
	$(CXX) $(CXXFLAGS) People.cpp

test: catchmain.o tests.o DNA.o People.o
	$(LD) catchmain.o tests.o DNA.o People.o $(LDFLAGS) -o test

catchmain.o : catch/catchmain.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

tests.o : tests/tests.cpp catch/catch.hpp run.cpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean:
	rm -f *.o $(EXENAME) test

	
