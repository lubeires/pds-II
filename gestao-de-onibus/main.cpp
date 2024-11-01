#include <iostream>

#include "Onibus.hpp"
#include "Empresa.hpp"

int main()
{
    Empresa *empresa = new Empresa;
    Onibus *onibus, *onibus_trnsf;
    char operacao = ' ';
    std::string placa = "", placa_trnsf = "";
    int capacidade = 0, quantidade = 0;
    bool sucesso = false;
    while (operacao != 'F')
    {
        std::cin >> operacao;
        switch (operacao)
        {
        case 'C':
            std::cin >> placa >> capacidade;
            sucesso = empresa->adicionar_onibus(placa, capacidade);
            std::cout << (sucesso ? "novo onibus cadastrado" : "ERRO : onibus repetido") << std::endl;
            break;
        case 'S':
            std::cin >> placa >> quantidade;
            onibus = empresa->buscar_onibus(placa);
            if (!onibus)
                std::cout << "ERRO : onibus inexistente";
            else
            {
                sucesso = onibus->subir_passageiros(quantidade);
                std::cout << (sucesso ? "passageiros subiram com sucesso" : "ERRO : onibus lotado") << std::endl;
            }
            break;
        case 'D':
            std::cin >> placa >> quantidade;
            onibus = empresa->buscar_onibus(placa);
            if (!onibus)
                std::cout << "ERRO : onibus inexistente";
            else
            {
                sucesso = onibus->descer_passageiros(quantidade);
                std::cout << (sucesso ? "passageiros desceram com sucesso" : "ERRO : faltam passageiros") << std::endl;
            }
            break;
        case 'T':
            std::cin >> placa >> placa_trnsf >> quantidade;
            onibus = empresa->buscar_onibus(placa);
            onibus_trnsf = empresa->buscar_onibus(placa_trnsf);
            if (!onibus || !onibus_trnsf)
                std::cout << "ERRO : onibus inexistente";
            else
            {
                sucesso = onibus->transferir_passageiros(onibus_trnsf, quantidade);
                std::cout << (sucesso ? "transferencia de passageiros efetuada" : "ERRO : transferencia cancelada") << std::endl;
            }
            break;
        case 'I':
            empresa->imprimir_estado();
            break;
        default:
            break;
        }
    }
    delete (empresa);
    return 0;
}