CXX = g++
FLAGS = -Wall -std=c++11

test: queues.o main.o
	$(CXX) $(FLAGS) -o test queues.o main.o

main.o: main.cpp
	$(CXX) $(FLAGS) -c main.cpp

queues.o: queues.hpp
	$(CXX) $(FLAGS) -c queues.hpp
