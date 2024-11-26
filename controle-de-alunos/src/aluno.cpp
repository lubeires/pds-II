#include "aluno.hpp"
#include <algorithm>
#include <numeric>

Aluno::Aluno(std::string nome, int matricula) : _nome(nome), _matricula(matricula) {};

std::string Aluno::getNome() const
{
    return _nome;
}

int Aluno::getMatricula() const
{
    return _matricula;
}

std::vector<int> Aluno::getNotas() const
{
    return _notas;
}

void Aluno::incluirNota(int nota)
{
    _notas.push_back(nota);
}

float Aluno::calcularMedia()
{
    return std::accumulate(_notas.begin(), _notas.end(), 0) / (float)_notas.size();
}

int Aluno::maiorNota()
{
    return *max_element(_notas.begin(), _notas.end());
}

int Aluno::menorNota()
{
    return *min_element(_notas.begin(), _notas.end());
}