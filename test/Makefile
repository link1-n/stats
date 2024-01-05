include ../build/common_flags.mk

PROJECTS = rollingStats_test movingAverage_test movingAverageClass_test

INC_FLAGS = -I ../include/
LIB_FLAGS = -L ../lib/ -lStats

all: $(foreach proj, $(PROJECTS), $(proj))

define build_executable
$(1): $(1).cpp
	@echo -e ${YELLOW}CREATING EXECUTABLE $(1)${NC}
	$(CXX) $(CXXFLAGS) $(DEFINE_FLAGS) $(INC_FLAGS) $(1).cpp -o $(1) $(LIB_FLAGS)
endef

.PHONY: clean

$(foreach proj, $(PROJECTS), $(eval $(call build_executable,$(proj))))

clean:
	rm -rf $(foreach proj, $(PROJECTS), $(proj) $(proj).dSYM) 

