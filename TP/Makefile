CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Email.o $(OBJ)/CelulaEmail.o $(OBJ)/CaixaDeEmail.o $(OBJ)/CelulaConta.o $(OBJ)/Conta.o $(OBJ)/ListaContas.o
HDRS = $(INC)/Email.hpp $(INC)/CelulaEmail.hpp $(INC)/CaixaDeEmail.hpp $(INC)/CelulaConta.hpp $(INC)/Conta.hpp $(INC)/ListaContas.hpp

EXE = $(BIN)/main

all:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -o $(EXE) $(SRC)/main.cpp $(OBJS) -Wall

$(OBJ)/Email.o: $(HDRS) $(SRC)/Email.cpp
	$(CC) -o $(OBJ)/Email.o $(SRC)/Email.cpp -c -Wall

$(OBJ)/CelulaEmail.o: $(HDRS) $(SRC)/CelulaEmail.cpp
	$(CC) -o $(OBJ)/CelulaEmail.o $(SRC)/CelulaEmail.cpp -c -Wall
	
$(OBJ)/CaixaDeEmail.o: $(HDRS) $(SRC)/CaixaDeEmail.cpp
	$(CC) -o $(OBJ)/CaixaDeEmail.o $(SRC)/CaixaDeEmail.cpp -c -Wall
	
$(OBJ)/CelulaConta.o: $(HDRS) $(SRC)/CelulaConta.cpp
	$(CC) -o $(OBJ)/CelulaConta.o $(SRC)/CelulaConta.cpp -c -Wall
	
$(OBJ)/Conta.o: $(HDRS) $(SRC)/Conta.cpp
	$(CC) -o $(OBJ)/Conta.o $(SRC)/Conta.cpp -c -Wall
	
$(OBJ)/ListaContas.o: $(HDRS) $(SRC)/ListaContas.cpp
	$(CC) -o $(OBJ)/ListaContas.o $(SRC)/ListaContas.cpp -c -Wall
	
clean:
	rm -f $(EXE) $(OBJS)
