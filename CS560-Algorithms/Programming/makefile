CXX = g++
CXXFLAGS = -Wall -std=c++11

test: maxima.o
	$(CXX) $(CXXFLAGS) -o test maxima.o

maxima.o: maxima.cpp
	$(CXX) $(CXXFLAGS) -c maxima.cpp