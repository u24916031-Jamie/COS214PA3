
# .o and executable need to recompiled when switching between wsl and windows
# windows executable runs on wsl but not vise versa
# .exe needs to be appended to run windows executable on wsl 


# Target executable, default name
TARGET= eventflow
SUBDIRS  := EventGroups EventUnits
INC_FLAGS := $(addprefix -Isrc/, $(SUBDIRS))
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Werror -I. -Isrc $(INC_FLAGS)

##DO NOT TOUCH----------------------------------------------------------------------

# Compiler
CXX = g++

# all method names
.PHONY: all clean run valgrind

#Don't delete .o
.PRECIOUS: obj/%.o

# Source files
SRCS=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp)

# Object files
OBJSTEMP = $(SRCS:.cpp=.o)

OBJS2=$(patsubst src/%,%,$(OBJSTEMP))

OBJS3=$(subst /, ,$(OBJS2))

OBJ_DIR=$(sort $(patsubst %.o,,$(OBJS3)))


OBJS=$(patsubst src/%,obj/%,$(OBJSTEMP))

all: $(TARGET) run


$(TARGET): $(OBJS) $(SRCS) |bin
	$(CXX) $(CXXFLAGS) -o bin/$(TARGET) $(OBJS)


obj/%.o: src/%.cpp | obj/$(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: $(TARGET) $(SRCS) $(OBJS) 
	./bin/$(TARGET)

clean:
	rm -f $(OBJS) bin/$(TARGET) 

# Run valgrind
valgrind:$(TARGET) $(SRCS) $(OBJS) 
	valgrind --leak-check=full ./bin/$(TARGET)

#create directory if needed
obj/$(OBJ_DIR):
	mkdir -p obj/$(OBJ_DIR)

bin:
	mkdir -p bin
	