#include "Onibus.hpp"
#include <iostream>

Onibus::Onibus(std::string placa, int capacidade)
{
    _placa = placa;
    _capacidade = capacidade;
    _lotacao = 0;
}

bool Onibus::subir_passageiros(int quantidade)
{
    if (_lotacao + quantidade > _capacidade)
        return false;
    _lotacao += quantidade;
    return true;
}

bool Onibus::descer_passageiros(int quantidade)
{
    if (_lotacao - quantidade < 0)
        return false;
    _lotacao -= quantidade;
    return true;
}

bool Onibus::transferir_passageiros(Onibus *onibus, int quantidade)
{
    if (this->descer_passageiros(quantidade) && onibus->subir_passageiros(quantidade))
        return true;
    return false;
}

void Onibus::imprimir_estado()
{
    std::cout << _placa << " (" << _lotacao << '/' << _capacidade << ")" << std::endl;
}