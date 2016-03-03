BIN = bin
SRC = src
OBJ = obj
LIB = lib
INC = include

all : $(BIN)/central

bin/central: $(OBJ)/central.o $(LIB)/libformas.a
	g++ -o $(BIN)/central $(OBJ)/central.o -Llib/ -lformas

lib/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rsv $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

obj/punto.o: $(SRC)/punto.cpp $(INC)/punto.h
	g++ -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -Iinclude/

obj/circulo.o: $(SRC)/circulo.cpp  $(INC)/circulo.h $(INC)/punto.h
	g++ -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -Iinclude/

obj/central.o: $(SRC)/central.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ -c $(SRC)/central.cpp -o $(OBJ)/central.o -Iinclude/

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o lib/lib*.a

mrproper: clean
	rm $(BIN)/central
