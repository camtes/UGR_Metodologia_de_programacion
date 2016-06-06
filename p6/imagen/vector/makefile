
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)

all: $(BIN)/testimagen $(BIN)/suma $(BIN)/testarteASCII $(BIN)/arteASCII $(BIN)/arteASCII2

bin/testimagen: $(OBJ)/testimagen.o $(LIB)/libimage.a
	g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o -Llib/ -limage

bin/suma:  $(OBJ)/suma.o $(LIB)/libimage.a
	g++ -o $(BIN)/suma $(OBJ)/suma.o -Llib/ -limage

bin/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimage.a
	g++ -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o -Llib/ -limage

bin/arteASCII2: $(OBJ)/arteASCII2.o $(LIB)/libimage.a
	g++ -o $(BIN)/arteASCII2 $(OBJ)/arteASCII2.o -Llib/ -limage

bin/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimage.a
	g++ -o $(BIN)/arteASCII $(OBJ)/arteASCII.o -Llib/ -limage

lib/libimage.a: $(OBJ)/imagen.o $(OBJ)/byte.o $(OBJ)/pgm.o $(OBJ)/lista.o
	ar rsv $(LIB)/libimage.a $(OBJ)/imagen.o $(OBJ)/byte.o $(OBJ)/pgm.o $(OBJ)/lista.o

obj/imagen.o: $(SRC)/imagen.cpp  $(INC)/imagen.h
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -Iinclude/

obj/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -Iinclude/

obj/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	g++ -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -Iinclude/

obj/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	g++ -c $(SRC)/lista.cpp -o $(OBJ)/lista.o -Iinclude/

obj/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -Iinclude/

obj/suma.o: $(SRC)/suma.cpp $(INC)/imagen.h $(INC)/lista.h
	g++ -c $(SRC)/suma.cpp -o $(OBJ)/suma.o -Iinclude/

obj/testarteASCII.o: $(SRC)/testarteASCII.cpp $(INC)/imagen.h
	g++ -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -Iinclude/

obj/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	g++ -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -Iinclude/

obj/arteASCII2.o: $(SRC)/arteASCII2.cpp $(INC)/imagen.h $(INC)/lista.h
	g++ -c $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o -Iinclude/

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o lib/lib*.a

mrproper: clean
	rm $(BIN)/*

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
