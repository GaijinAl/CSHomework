CXX = g++
CXXFLAGS = -Wall -std=c++11

test: LinkedList.o main.o
	$(CXX) $(CXXFLAGS) -o test LinkedList.o main.o

ArrayList.o: LinkedList.cpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
