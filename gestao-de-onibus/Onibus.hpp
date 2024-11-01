#ifndef ONIBUS_H
#define ONIBUS_H

#include <string>

struct Onibus
{
    std::string _placa;
    int _capacidade, _lotacao;

    Onibus(std::string, int);
    bool subir_passageiros(int);
    bool descer_passageiros(int);
    bool transferir_passageiros(Onibus *, int);
    void imprimir_estado();
};

#endif