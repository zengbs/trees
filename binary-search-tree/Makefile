MACRO :=


CC   := g++

CC_FLAGS      = -lm --std=c++1z -O3
CC_DEBUG_FLAG = -g -Wall


INC :=
LIB :=


EXECUTABLE := a.out


# Source files
CC_FILE =  main.cpp delete.cpp insert.cpp search.cpp validate.cpp utilities.cpp
SRC_PATH = src
CC_SRC = $(patsubst %,$(SRC_PATH)/%,$(CC_FILE))


# Object files
CC_OBJ_FILE = $(CC_FILE:.cpp=.o)
OBJ_PATH    = objective
CC_OBJ      = $(patsubst %,$(OBJ_PATH)/%,$(CC_OBJ_FILE))


# Header files
HEADER_FILE = macro.hpp prototypes.hpp typedef.hpp
INC_PATH    = includes
HEADER      = $(patsubst %,$(INC_PATH)/%,$(HEADER_FILE))

CC_ALL_FLAG   = $(CC_DEBUG_FLAG)  $(INC) $(CC_FLAGS) $(MACRO)


# Compiling
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.cpp $(HEADER)
	$(CC) $(CC_ALL_FLAG) -o $@ -c $<


# Linking
$(EXECUTABLE): $(CC_OBJ) $(CUDA_OBJ)
	g++ -o $@ $^  $(LIB)  -lm
	mv $(EXECUTABLE) bin/

.PHONY:
clean:
	@rm -rf ${OBJ_PATH}/*.o rm bin/${EXECUTABLE}

