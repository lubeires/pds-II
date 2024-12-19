#include <iostream>

template <typename T>
class Vetor
{
private:
    T *_elementos;
    int _qtd_elementos;
    int _tam_max_vetor;

public:
    Vetor(int n) : _qtd_elementos(0), _tam_max_vetor(n) { _elementos = new T[n]; }
    Vetor(const Vetor &v)
    {
        _qtd_elementos = v._qtd_elementos;
        _tam_max_vetor = v._tam_max_vetor;
        _elementos = new T[_tam_max_vetor];
        for (int i = 0; i < _qtd_elementos; i++)
            _elementos[i] = v._elementos[i];
    }
    ~Vetor() { delete[] _elementos; }
    void SetElemento(int i, T e) { _elementos[i] = e; }
    T GetElemento(int i) { return _elementos[i]; }
    void AdicionaElemento(T e) { _elementos[_qtd_elementos++] = e; }
    void Imprime()
    {
        for (int i = 0; i < _qtd_elementos; i++)
            std::cout << _elementos[i] << ' ';
        std::cout << std::endl;
    }
};