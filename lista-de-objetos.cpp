#include <iostream>
#include <list>
#include <iterator>

class Elemento
{
private:
    int _id;
    inline static int qtd = 0;
    inline static int autoid = 1;

public:
    Elemento() : Elemento(autoid++) {};
    Elemento(int id) : _id(id)
    {
        qtd++;
        this->imprimirElemento();
    };
    ~Elemento() { qtd--; }
    int getID() const { return this->_id; }
    int static getQuantidade() { return qtd; }
    Elemento *getElemento() { return this; }
    void imprimirElemento()
    {
        std::cout << this->_id << ' ' << this->getElemento() << std::endl;
    }
};

int main()
{
    std::list<Elemento *> lista;
    std::list<Elemento *>::iterator it;
    char opcao;
    while (std::cin >> opcao)
    {
        switch (opcao)
        {
        case 'A':
            lista.push_back(new Elemento());
            break;
        case 'C':
            int id;
            std::cin >> id;
            if (id < 0)
                lista.push_front(new Elemento(id));
            else
                std::cout << "ERRO" << std::endl;
            break;
        case 'R':
            if (lista.empty())
                std::cout << "ERRO" << std::endl;
            else
            {

                Elemento *e = lista.front();
                e->imprimirElemento();
                delete (e);
                lista.pop_front();
            }
            break;
        case 'N':
            std::cout << Elemento::getQuantidade() << std::endl;
            break;
        case 'P':
            int pos;
            std::cin >> pos;
            if (pos < 1 || pos > Elemento::getQuantidade())
                std::cout << "ERRO" << std::endl;
            else
            {
                it = lista.begin();
                std::advance(it, pos - 1);
                (*it)->imprimirElemento();
            }
            break;
        case 'L':
            for (it = lista.begin(); it != lista.end(); it++)
                (*it)->imprimirElemento();
            break;
        case 'E':
            break;

        default:
            break;
        }
    }
    return 0;
}