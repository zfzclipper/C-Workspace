#Compiler:
#gcc for C program
#g++ for C++ program
CXX = g++

#Compiler Flags:
#-g	adds debugging information to the executable file
#-Wall	turns on most, but not all, compiler warnings
CXXFLAGS = -g -std=c++11 -Wall

SRCS = heapSort.cpp
TARGET = test

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
clean:
	rm -rf $(TARGET)
