BIN = bin
SRC = src
OBJ = obj
LIB = lib
INC = include

all : $(BIN)/boqueLed

bin/central: $(OBJ)/test.o $(LIB)/libLed.a
	g++ -o $(BIN)/bloqueLed $(OBJ)/central.o -Llib/ -lformas

lib/libLed.a: $(OBJ)/bloqueLed.o
	ar rsv $(LIB)/libLed.a $(OBJ)/bloqueLed.o

obj/test.o: $(SRC)/test.cpp $(INC)/bloqueLed.h
	g++ -c $(SRC)/test.cpp -o $(OBJ)/bloqueLed.o -Iinclude/

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o lib/lib*.a

mrproper: clean
	rm $(BIN)/central
