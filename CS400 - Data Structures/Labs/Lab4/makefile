CXX = g++
FLAGS = -Wall -std=c++11

test: DoubleLinkedList.o main.o
	$(CXX) $(FLAGS) -o test DoubleLinkedList.o main.o

DoubleLinkedList.o: DoubleLinkedList.cpp DoubleLinkedList.hpp
	$(CXX) $(FLAGS) -c DoubleLinkedList.cpp

main.o: main.cpp
	$(CXX) $(FLAGS) -c main.cpp
