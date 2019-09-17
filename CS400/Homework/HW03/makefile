CXX = g++
CXXFLAGS = -Wall -std=c++11

test: LinkedList.o main.o
	$(CXX) $(CXXFLAGS) -o LinkedList.o

ArrayList.o: LinkedList.cpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
