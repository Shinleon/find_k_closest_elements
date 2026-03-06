CC=g++
CXXFLAGS=-Wall -Wpedantic -Wextra -std=c++14
TARGET=main.a
.PHONY: all



all: $(TARGET) 

$(TARGET): main.cpp
	$(CC) $(CXXFLAGS) $< -o $@

clean: 
	rm -rf *.o $(TARGET)
