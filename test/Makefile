include ../build/common_flags.mk

MODULES = stats

PROJECT = main

INC_FLAGS = -I ../include/
LIB_FLAGS = ../lib/MovingAverage.o

all: $(PROJECT)

$(PROJECT): $(PROJECT).cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $(LIB_FLAGS) $(PROJECT).cpp -o $(PROJECT)

.PHONY: clean

clean:
	rm $(PROJECT)
	rm -rf $(PROJECT).dSYM

