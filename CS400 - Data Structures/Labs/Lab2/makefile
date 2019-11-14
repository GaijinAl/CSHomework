CXX = g++
CXXFLAGS = -Wall -std=c++11

test: DynamicArray.o main.o
	$(CXX) $(CXXFLAGS) -o test DynamicArray.o main.o

DynamicArray.o: DynamicArray.cpp DynamicArray.hpp
	$(CXX) $(CXXFLAGS) -c DynamicArray.cpp

main.o: main.cpp DynamicArray.cpp DynamicArray.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
