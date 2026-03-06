CC=g++
CXXFLAGS ?= -Wall -Wpedantic
output=-o
TARGET=main.a

ifdef DEBUG
	CXXFLAGS += -g
endif

ifdef PROFILE
	CXXFLAGS += -pg
endif

.PHONY: all
all: $(TARGET)

$(TARGET): main.o TwoPointerSolution.o PriorityQueueSolution.o 
	$(CC) $(CXXFLAGS) $^ $(output) $@ -Iinc

main.o: main.cxx 
	$(CC) -c $(CXXFLAGS) $< $(output) $@ -Iinc

TwoPointerSolution.o: src/TwoPointerSolution.cxx
	$(CC) -c $(CXXFLAGS) $< -Iinc

PriorityQueueSolution.o: src/PriorityQueueSolution.cxx
	$(CC) -c $(CXXFLAGS) $< -Iinc

.PHONY: clean
clean:
	rm -rf $(TARGET) *.o
	rm -rf *.out
	rm -rf *.stats

.PHONY: test_target
test_target:
	echo $(PARAM)
