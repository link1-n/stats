include ../build/common_flags.mk

PROJECTS = MovingAverage MeanDev

INC_DIR = ../include
LIB_DIR = ../lib

DEFINE_FLAGS = -DMA_DEBUG

all: $(foreach proj, $(PROJECTS), $(LIB_DIR)/$(proj).o $(LIB_DIR)/lib$(proj).a)

define build_project
$(LIB_DIR)/$(1).o: $(1).cpp $(INC_DIR)/$(1).h | $(LIB_DIR)
	@echo -e ${YELLOW}BUILDING $(1)${NC}
	$(CXX) $(CXXFLAGS) $(DEFINE_FLAGS) -I$(INC_DIR) -c $(1).cpp -o $(LIB_DIR)/$(1).o

$(LIB_DIR)/lib$(1).a: $(LIB_DIR)/$(1).o
	ar rcs $(LIB_DIR)/lib$(1).a $(LIB_DIR)/$(1).o
endef

$(foreach proj, $(PROJECTS), $(eval $(call build_project,$(proj))))

$(LIB_DIR):
	@echo -e ${YELLOW}LIBS FOLDER DOES NOT EXIST, CREATING IT..${NC}
	mkdir -p $@

.PHONY: clean
clean:
	@echo -e ${RED}CLEANING PROJECTS${NC}
	rm -f $(foreach proj, $(PROJECTS), $(LIB_DIR)/$(proj).o $(LIB_DIR)/lib$(proj).a)

