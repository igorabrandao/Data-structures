### Programas
CXX = g++
DEL = /bin/rm

### Variáveis
#DEPURA = -ggdb
AVISA = -Wall
#PROFILA = -pg
#OTIMIZA = -O2
PADRAO_LINGUAGEM = c++17  #c++0x  # c++98
BIBLIOTECA_PADRAO = libc++
#BIBLIOTECAS = -lm


### Diretórios
#DIRBIBLIOTECAS = -L/opt/local/lib
DIRDECLARACOES = -I include
DIREXECUTAVEL = bin
DIRFONTE = src
DIRINCLUDE = include

### Flags de compilação
CFLAGS = $(AVISA) $(DEPURA)$ $(PROFILA) $(OTIMIZA) -std=$(PADRAO_LINGUAGEM)

### Flags de linkedição
LFLAGS = $(AVISA) $(DIRBIBLIOTECAS) $(BIBLIOTECAS) -stdlib=$(BIBLIOTECA_PADRAO) 

### Dependências 1ro programa
OBJS1 = $(DIREXECUTAVEL)/vetor.o $(DIREXECUTAVEL)/drive_vetor.o # outras ...

### Dependências 2do programa
OBJS2 = $(DIREXECUTAVEL)/vetor.o $(DIREXECUTAVEL)/distancia.o # outras ...

### --------------------------------------------------------------------
### Cada entrada do Makefile/makefile segue a seguinte sintaxe:
### Regras: Dependencia_1 Dependencia_2 ...
### <tab>Comando_1
### <tab>Comando_2
### ...
###
### Uma regra pode ser um arquivo ou uma outra regra.
### --------------------------------------------------------------------

### --------------------------------------------------------------------
### Entrada principal #0: compilar os 2 programas.
### --------------------------------------------------------------------
all: drive_vetor distancia

### --------------------------------------------------------------------
### Entrada principal #1
### --------------------------------------------------------------------
# A primeira entrada eh para o primeiro programa alvo
drive_vetor: $(OBJS1)
	$(CXX) $(LFLAGS) $(OBJS1) -o $(DIREXECUTAVEL)/drive_vetor 

# Resolvendo 1ra dependência do primeiro programa alvo.
# Essa entrada define como produzir o arquivo
$(DIREXECUTAVEL)/vetor.o: $(DIRFONTE)/vetor.cpp $(DIRINCLUDE)/vetor.h
	$(CXX) $(CFLAGS) -c $(DIRDECLARACOES) $(DIRFONTE)/vetor.cpp -o \
	    $(DIREXECUTAVEL)/vetor.o

# Resolvendo 2da dependência do primeiro programa alvo.
# Essa entrada define como produzir o arquivo
$(DIREXECUTAVEL)/drive_vetor.o: $(DIRFONTE)/drive_vetor.cpp
	$(CXX) $(CFLAGS) -c $(DIRDECLARACOES) $(DIRFONTE)/drive_vetor.cpp -o \
	    $(DIREXECUTAVEL)/drive_vetor.o

# Dependência do .h
$(DIRFONTE)/vetor.cpp: $(DIRINCLUDE)/vetor.h

$(DIRFONTE)/drive_vetor.cpp: $(DIRFONTE)/vetor.cpp

$(DIRFONTE)/distancia.cpp: $(DIRFONTE)/vetor.cpp


### --------------------------------------------------------------------
### Entrada principal #2
### --------------------------------------------------------------------
# A primeira entrada eh para o primeiro programa alvo
distancia: $(OBJS2)
	$(CXX) $(LFLAGS) $(OBJS2) -o $(DIREXECUTAVEL)/distancia

# Resolvendo 2da dependência do primeiro programa alvo.
# Essa entrada define como produzir o arquivo
$(DIREXECUTAVEL)/distancia.o: $(DIRFONTE)/distancia.cpp
	$(CXX) $(CFLAGS) -c $(DIRDECLARACOES) $(DIRFONTE)/distancia.cpp -o \
	    $(DIREXECUTAVEL)/distancia.o

### Entrada principal #3
# a entrada seguinte elimina os arquivos inuteis.
clean:
	$(DEL) $(DIREXECUTAVEL)/*.o $(DIRFONTE)/*~ \
	    $(DIREXECUTAVEL)/drive_vetor $(DIREXECUTAVEL)/distancia

