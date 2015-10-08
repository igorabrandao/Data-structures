SOURCE = $(wildcards src=*.cpp)

AVISA = -Wall
DEBUG = -g
LANGUAGE_VERSION = -std=c++11
BIN_DIR = ./bin/
CFLAGS = $(AVISA) $(LANGUAGE_VERSION) $(DEBUG)

all: 
	@echo "Compilando direto..."
	g++ $(CFLAGS) src/drive_list.cpp -I include -o bin/app

exe:
	$(BIN_DIR)app

val:
	valgrind $(BIN_DIR)app

.PHONY: clean
clean:
	@echo "Limpando apenas executavel por enquanto"
	rm $(BIN_DIR)app