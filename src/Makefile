include ../build/common_flags.mk

PROJECT = MovingAverage

INC_DIR = ../include
LIB_DIR = ../lib

#DEFINE_FLAGS = -DMA_DEBUG

all: $(LIB_DIR)/$(PROJECT).o $(LIB_DIR)/lib$(PROJECT).a

$(LIB_DIR)/$(PROJECT).o: $(PROJECT).cpp $(INC_DIR)/$(PROJECT).h | $(LIB_DIR)
	@echo -e ${YELLOW}BUILDING $(PROJECT)${NC}
	$(CXX) $(CXXFLAGS) $(DEFINE_FLAGS) -I$(INC_DIR) -c $(PROJECT).cpp -o $(LIB_DIR)/$(PROJECT).o

$(LIB_DIR)/lib$(PROJECT).a: $(LIB_DIR)/$(PROJECT).o
	ar rcs $(LIB_DIR)/lib$(PROJECT).a $(LIB_DIR)/$(PROJECT).o

$(LIB_DIR):
	@echo -e ${YELLOW}LIBS FOLDER DOES NOT EXIST, CREATING IT..${NC}
	mkdir -p $@

.PHONY: clean
clean:
	@echo -e ${RED}CLEAN $(PROJECT)${NC}
	rm -f $(LIB_DIR)/$(PROJECT).o $(LIB_DIR)/lib$(PROJECT).a
