include ../build/common_flags.mk

MODULES = stats

INC_FLAGS = -I ../include/

LIB_FLAGS = -L ../lib/
LIB_FLAGS += -lMovingAverage
LIB_FLAGS += -lMeanDev

PROJECT_MAIN = main
PROJECT_CLASS = mainClass
PROJECT_STD = mainStd

all: $(PROJECT_MAIN) $(PROJECT_CLASS) $(PROJECT_STD)

$(PROJECT_MAIN): $(PROJECT_MAIN).cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $(LIB_FLAGS) $(PROJECT_MAIN).cpp -o \
		$(PROJECT_MAIN)

$(PROJECT_CLASS): $(PROJECT_CLASS).cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $(LIB_FLAGS) $(PROJECT_CLASS).cpp -o \
		$(PROJECT_CLASS)

$(PROJECT_STD): $(PROJECT_STD).cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $(LIB_FLAGS) $(PROJECT_STD).cpp -o \
		$(PROJECT_STD)

.PHONY: clean

clean:
	rm $(PROJECT_MAIN)
	rm -rf $(PROJECT_MAIN).dSYM
	rm $(PROJECT_CLASS)
	rm -rf $(PROJECT_CLASS).dSYM

