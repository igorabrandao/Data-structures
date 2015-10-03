####################################################
## 	Makefile											
#	author Leandro Antonio Feliciano da Silva		
#	data: 26 set 2015								
####################################################
#rodando o programa
SOURCES = $(wildcard src/*.cpp)

CC      = g++
CFLAGS  = -c -g -Wall -std=c++11

INC_DIR = ./include
BIN_DIR = ./bin
APP     = $(BIN_DIR)/app

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(APP)
    
$(APP): $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

.cpp.o:
	$(CC) $< -o $@ $(CFLAGS) -I$(INC_DIR)


clean:
	@echo "Eliminando arquivos inuteis"
	$(DELETAR) $(DIRFONTE)/*.o $(DIREXECUTAVEL)/*