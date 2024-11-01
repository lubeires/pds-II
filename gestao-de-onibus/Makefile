CC=g++
CFLAGS=-std=c++11 -Wall

all: main

Onibus.o: Onibus.hpp Onibus.cpp
	${CC} ${CFLAGS} -c Onibus.cpp

Empresa.o: Empresa.hpp Empresa.cpp
	${CC} ${CFLAGS} -c Empresa.cpp

main.o: Onibus.hpp Empresa.hpp main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o Empresa.o Onibus.o
	${CC} ${CFLAGS} main.o Empresa.o Onibus.o -o main

clean:
	rm -f main *.o