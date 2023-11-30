MACRO :=


CC   := g++

CC_FLAGS      = -lm --std=c++1z   -O3 #-frounding-math
CC_DEBUG_FLAG = -g -Wall


INC :=
LIB :=


EXECUTABLE := a.out


## source files
CC_SRC =  main.cpp delete.cpp insert.cpp search.cpp validate.cpp utilities.cpp

## object files
CC_OBJ_FILE = $(CC_SRC:.cpp=.o)
OBJ_PATH    = objective
CC_OBJ      = $(patsubst %,$(OBJ_PATH)/%,$(CC_OBJ_FILE))


# header files
HEADER_FILE = macro.hpp prototypes.hpp typedef.hpp
INC_PATH    = includes
HEADER      = $(patsubst %,$(INC_PATH)/%,$(HEADER_FILE))

CC_ALL_FLAG   = $(CC_DEBUG_FLAG)  $(INC) $(CC_FLAGS) $(MACRO)
CUDA_ALL_FLAG = $(INC) $(CUDA_FLAGS) $(MACRO)

# Compiling
$(OBJ_PATH)/%.o : %.cpp $(HEADER)
	$(CC) $(CC_ALL_FLAG) -o $@ -c $<


# Linking
$(EXECUTABLE): $(CC_OBJ) $(CUDA_OBJ)
	g++ -o $@ $^  $(LIB)  -lm -pthread -frounding-math
	mv $(EXECUTABLE) bin/

.PHONY:
clean:
	@rm -rf ${OBJ_PATH}/*.o rm ${EXECUTABLE}

