BIN = bin
SRC = src
OBJ = obj
LIB = lib
INC = include

all : $(BIN)/bloqueLed

bin/bloqueLed: $(OBJ)/test.o $(LIB)/libled.a
	g++ -o $(BIN)/bloqueLed $(OBJ)/test.o -Llib/ -lled

lib/libled.a: $(OBJ)/bloqueLed.o
	ar rsv $(LIB)/libled.a $(OBJ)/bloqueLed.o

obj/bloqueLed.o: $(SRC)/bloqueLed.cpp  $(INC)/bloqueLed.h
	g++ -c $(SRC)/bloqueLed.cpp -o $(OBJ)/bloqueLed.o -Iinclude/

obj/test.o: $(SRC)/test.cpp $(INC)/bloqueLed.h
	g++ -c $(SRC)/test.cpp -o $(OBJ)/test.o -Iinclude/

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o lib/lib*.a

mrproper: clean
	rm $(BIN)/bloqueLed
