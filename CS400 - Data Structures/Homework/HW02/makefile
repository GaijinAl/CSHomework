CXX = g++
CXXFLAGS = -Wall -std=c++11

test: ArrayList.o Car.o main.o
	$(CXX) $(CXXFLAGS) -o test ArrayList.o Car.o main.o

ArrayList.o: ArrayList.cpp
	$(CXX) $(CXXFLAGS) -c ArrayList.cpp

main.o: main.cpp ArrayList.cpp ArrayList.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Car.o: Car.cpp
	$(CXX) $(CXXFLAGS) -c Car.cpp
