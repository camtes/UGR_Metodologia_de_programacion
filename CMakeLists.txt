cmake_minimum_required(VERSION 3.5)
project(Practicas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    p0/fruteria.cp
    p0/tiempo.cpp
    p1/version1/circulomedio.cp
    p1/version2/include/circulo.h
    p1/version2/include/punto.h
    p1/version2/src/central.cpp
    p1/version2/src/circulo.cpp
    p1/version2/src/punto.cpp
    p1/version3/include/circulo.h
    p1/version3/include/punto.h
    p1/version3/src/central.cpp
    p1/version3/src/circulo.cpp
    p1/version3/src/punto.cpp
    p1/version4/include/circulo.h
    p1/version4/include/punto.h
    p1/version4/src/central.cpp
    p1/version4/src/circulo.cpp
    p1/version4/src/punto.cpp
    p2/include/bloqueLed.h
    p2/src/bloqueLed.cpp
    p2/src/test.cpp
    p3/include/byte.h
    p3/include/imagen.h
    p3/include/pgm.h
    p3/src/arteASCII.cpp
    p3/src/byte.cpp
    p3/src/imagen.cpp
    p3/src/pgm.cpp
    p3/src/testarteASCII.cpp
    p3/src/testimagen.cpp
    p3/src/testplano.cpp
    p4/include/byte.h
    p4/include/imagen.h
    p4/include/pgm.h
    p4/src/arteASCII.cpp
    p4/src/byte.cpp
    p4/src/imagen.cpp
    p4/src/pgm.cpp
    p4/src/testarteASCII.cpp
    p4/src/testimagen.cpp
    p4/src/testplano.cpp
    p5/include/byte.h
    p5/include/imagen.h
    p5/include/pgm.h
    p5/src/arteASCII.cpp
    p5/src/byte.cpp
    p5/src/imagen.cpp
    p5/src/pgm.cpp
    p5/src/testarteASCII.cpp
    p5/src/testimagen.cpp
    p5/src/testplano.cpp
    p5/arteASCII2.cpp
    p5/lista.cpp
    p5/lista.h)

add_executable(Practicas ${SOURCE_FILES})