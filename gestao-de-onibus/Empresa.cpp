#include "Empresa.hpp"

Empresa::Empresa()
{
    _quantidade_onibus = 0;
    for (int i = 0; i < MAX_ONIBUS; i++)
        _v_onibus[i] = nullptr;
}

Onibus *Empresa::adicionar_onibus(std::string placa, int capacidade)
{
    if (buscar_onibus(placa))
        return nullptr;
    Onibus *o = new Onibus(placa, capacidade);
    _v_onibus[_quantidade_onibus] = o;
    _quantidade_onibus++;
    return o;
}

Onibus *Empresa::buscar_onibus(std::string placa)
{
    for (int i = 0; i < _quantidade_onibus; i++)
    {
        if (_v_onibus[i]->_placa == placa)
            return _v_onibus[i];
    }
    return nullptr;
}

void Empresa::imprimir_estado()
{
    for (int i = 0; i < _quantidade_onibus; i++)
        _v_onibus[i]->imprimir_estado();
}