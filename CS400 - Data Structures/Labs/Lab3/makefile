CXX = g++
CXXFLAGS = -Wall -std=c++11

test: Car.o main.o
	$(CXX) $(CXXFLAGS) -o test ArrayList.o Car.o main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Car.o: Car.cpp
	$(CXX) $(CXXFLAGS) -c Car.cpp
