# ====================================================
# Makefile build 'MemCell project' using Make
# ====================================================
SOURCES = $(wildcard src/drive.cpp)

CC      = g++
CFLAGS  = -c -g -Wall -std=c++17

INC_DIR = ./include
BIN_DIR = ./bin
APP     = $(BIN_DIR)/matrix
LIB_DIR = 
LIBS = 

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(APP)
    
$(APP): $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

.cpp.o:
	$(CC) $< -o $@ $(CFLAGS) -I$(INC_DIR)

.PHONY: clean
clean:
	rm $(OBJECTS) $(APP)

exe:
	$(APP)

val:
	valgrind $(APP)