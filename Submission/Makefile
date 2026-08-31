
CXX      := g++
SUBDIRS  := EventGroups EventUnits
INC_FLAGS := $(addprefix -Isrc/, $(SUBDIRS))
CXXFLAGS  := -Wall -Wextra -std=c++11
TARGET   := eventFlow


SRCS :=  $(wildcard *.cpp)
HEADERS:=$(wildcard *.h)

PDFS := COS214_PA1.pdf

ZIP_NAME=prac.zip


	

all: $(TARGET)
	make run

$(TARGET): 
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@
	
	
$(TARGETTEST): 
	$(CXX) $(CXXFLAGSTEST) $(SRCS) -o $@

zip:
	zip $(ZIP_NAME) $(SRCS) $(HEADERS) $(PDFS) Makefile 


run: $(TARGET)
	./$(TARGET)

val:
	valgrind --leak-check=full $(TARGET)

clean:
	rm -f $(TARGET) $(ZIP_NAME)
