EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

.PHONY: all test stest clean

all : $(EXENAME)

$(EXENAME): main.o Person.o Analyzer.o PersonCollector.o
	$(LD) main.o Person.o Analyzer.o PersonCollector.o $(LDFLAGS) -o $(EXENAME)

main.o : src/main.cc includes/Person.h includes/Analyzer.h includes/PersonCollector.h
	$(CXX) $(CXXFLAGS) src/main.cc

PersonCollector.o: src/PersonCollector.cc includes/PersonCollector.h
	$(CXX) $(CXXFLAGS) src/PersonCollector.cc

Person.o : src/Person.cc includes/Person.h
	$(CXX) $(CXXFLAGS) src/Person.cc

Analyzer.o : src/Analyzer.cc includes/Analyzer.h
	$(CXX) $(CXXFLAGS) src/Analyzer.cc

test: catchmain.o test.o Person.o Analyzer.o PersonCollector.o
	$(LD) catchmain.o test.o Person.o Analyzer.o PersonCollector.o $(LDFLAGS) -o test

stest: catchmain.o separatetest.o Person.o Analyzer.o PersonCollector.o
	$(LD) catchmain.o separatetest.o Person.o Analyzer.o PersonCollector.o $(LDFLAGS) -o stest

catchmain.o : tests/catchmain.cc tests/catch.hpp
	$(CXX) $(CXXFLAGS) tests/catchmain.cc

test.o : tests/test.cc tests/catch.hpp src/main.cc
	$(CXX) $(CXXFLAGS) tests/test.cc

separatetest.o : tests/separatetest.cc tests/catch.hpp src/main.cc
	$(CXX) $(CXXFLAGS) tests/separatetest.cc

clean:
	rm -f *.o $(EXENAME) test