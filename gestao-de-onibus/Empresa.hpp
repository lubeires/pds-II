#ifndef EMPRESA_H
#define EMPRESA_H

#include "Onibus.hpp"
#define MAX_ONIBUS 20

struct Empresa
{
    int _quantidade_onibus;
    Onibus *_v_onibus[MAX_ONIBUS];

    Empresa();
    Onibus *adicionar_onibus(std::string, int);
    Onibus *buscar_onibus(std::string);
    void imprimir_estado();
};

#endif