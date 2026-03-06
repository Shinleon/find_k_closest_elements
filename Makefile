CC=g++
CXXFLAGS ?= -Wall -Wpedantic -Wextra -std=c++14
output=-o
TARGET=main.a
OBJ=obj
ifdef DEBUG
	CXXFLAGS += -g
endif

ifdef PROFILE
	CXXFLAGS += -pg
endif

.PHONY: all
all: $(TARGET)

$(TARGET): $(addprefix $(OBJ)/, main.o TwoPointerSolution.o PriorityQueueSolution.o )
	$(CC) $(CXXFLAGS) $^ $(output) $@ -Iinc

$(OBJ)/main.o: main.cxx 
	$(CC) -c $(CXXFLAGS) $< $(output) $@ -Iinc

$(OBJ)/TwoPointerSolution.o: src/TwoPointerSolution.cxx
	$(CC) -c $(CXXFLAGS) $< $(output) $@ -Iinc

$(OBJ)/PriorityQueueSolution.o: src/PriorityQueueSolution.cxx
	$(CC) -c $(CXXFLAGS) $< $(output) $@ -Iinc

.PHONY: clean
clean:
	rm -rf $(TARGET) *.o
	rm -rf $(OBJ)/*
	rm -rf *.stats

.PHONY: test_target
test_target:
	echo $(PARAM)
