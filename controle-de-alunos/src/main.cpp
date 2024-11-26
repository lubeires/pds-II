#include <iostream>
#include <set>
#include <algorithm>
#include "aluno.hpp"

struct ordenaPorNome
{
    bool operator()(const Aluno &a1, const Aluno &a2)
    {
        return a1.getNome() < a2.getNome();
    }
};

int main()
{
    std::set<Aluno, ordenaPorNome> alunos;
    std::string nome;
    int matricula;

    while (true)
    {
        std::cin >> nome;
        if (nome == "END")
            break;
        std::cin >> matricula;
        Aluno aluno(nome, matricula);
        int nota;
        while (true)
        {
            std::cin >> nota;
            if (nota < 0)
                break;
            aluno.incluirNota(nota);
        }
        alunos.insert(aluno);
    }

    for (Aluno a : alunos)
    {
        std::cout << a.getMatricula() << ' ' << a.getNome();
        for (int n : a.getNotas())
            std::cout << ' ' << n;
        std::cout << std::endl;
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << a.calcularMedia() << ' ' << a.maiorNota() << ' ' << a.menorNota() << std::endl;
    }

    return 0;
}