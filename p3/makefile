
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)

#all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen
all: $(BIN)/testimagen

bin/testimagen: $(OBJ)/testimagen.o $(LIB)/libimage.a
	g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o -Llib/ -limage

lib/libimage.a: $(OBJ)/imagen.o $(OBJ)/pgm.o
	ar rsv $(LIB)/libimage.a $(OBJ)/imagen.o $(OBJ)/pgm.o

obj/imagen.o: $(SRC)/imagen.cpp  $(INC)/imagen.h
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -Iinclude/

obj/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -Iinclude/

obj/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -Iinclude/

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o lib/lib*.a

mrproper: clean
	rm $(BIN)/*

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
