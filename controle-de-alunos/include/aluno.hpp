#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

class Aluno
{
private:
    std::string _nome;
    int _matricula;
    std::vector<int> _notas;

public:
    Aluno(std::string nome, int matricula);
    std::string getNome() const;
    int getMatricula() const;
    std::vector<int> getNotas() const;
    void incluirNota(int nota);
    float calcularMedia();
    int maiorNota();
    int menorNota();
};

#endif