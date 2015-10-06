all:
	@echo "Compilando direto..."
	g++ -Wall -std=c++11 src/drive_list.cpp -I include -o bin/app

exe:
	./bin/app

val:
	valgrind ./bin/app

.PHONY: clean
clean:
	@echo "Limpando apenas executavel por enquanto"
	rm bin/app