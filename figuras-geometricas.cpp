#include <iostream>
#include <cmath>
#include <numbers>
#include <vector>

class Ponto
{
private:
    int _x, _y;

public:
    Ponto(int x, int y);
    int get_x();
    void set_x(int x);
    int get_y();
    void set_y(int y);
};

Ponto::Ponto(int x, int y) : _x(x), _y(y) {};
int Ponto::get_x() { return this->_x; };
void Ponto::set_x(int x) { this->_x = x; };
int Ponto::get_y() { return this->_y; };
void Ponto::set_y(int y) { this->_y = y; };

class FiguraGeometrica
{
private:
    Ponto _centro;

public:
    FiguraGeometrica(Ponto centro);
    Ponto get_centro();
    void set_centro(Ponto centro);
    virtual void desenha();
    virtual float calcula_area() = 0;
};
FiguraGeometrica::FiguraGeometrica(Ponto centro) : _centro(centro) {};
Ponto FiguraGeometrica::get_centro() { return this->_centro; };
void FiguraGeometrica::set_centro(Ponto centro) { this->_centro = centro; };
void FiguraGeometrica::desenha() { std::cout << this->_centro.get_x() << ' ' << this->_centro.get_y(); }

class Retangulo : public FiguraGeometrica
{
private:
    int _lado1, _lado2;

public:
    Retangulo(Ponto centro, int lado1, int lado2);
    int get_lado1();
    void set_lado1(int lado1);
    int get_lado2();
    void set_lado2(int lado2);
    void desenha() override;
    virtual float calcula_area() override;
};

Retangulo::Retangulo(Ponto centro, int lado1, int lado2) : FiguraGeometrica(centro), _lado1(lado1), _lado2(lado2) {};
int Retangulo::get_lado1() { return this->_lado1; };
void Retangulo::set_lado1(int lado1) { this->_lado1 = lado1; };
int Retangulo::get_lado2() { return this->_lado2; };
void Retangulo::set_lado2(int lado2) { this->_lado2 = lado2; };
void Retangulo::desenha()
{
    this->FiguraGeometrica::desenha();
    std::cout << ' ' << "RETANGULO" << std::endl;
}
float Retangulo::calcula_area() { return this->_lado1 * this->_lado2; }

class Circulo : public FiguraGeometrica
{
private:
    int _raio;

public:
    Circulo(Ponto centro, int raio);
    int get_raio();
    void set_raio(int raio);
    void desenha() override;
    virtual float calcula_area() override;
};

Circulo::Circulo(Ponto centro, int raio) : FiguraGeometrica(centro), _raio(raio) {};
int Circulo::get_raio() { return this->_raio; };
void Circulo::set_raio(int raio) { this->_raio = raio; };
void Circulo::desenha()
{
    this->FiguraGeometrica::desenha();
    std::cout << ' ' << "CIRCULO" << std::endl;
}
float Circulo::calcula_area() { return M_PI * pow(this->_raio, 2); }

class Triangulo : public FiguraGeometrica
{
private:
    int _base, _altura;

public:
    Triangulo(Ponto centro, int base, int altura);
    int get_base();
    void set_base(int base);
    int get_altura();
    void set_altura(int altura);
    void desenha() override;
    virtual float calcula_area() override;
};

Triangulo::Triangulo(Ponto centro, int base, int altura) : FiguraGeometrica(centro), _base(base), _altura(altura) {};
int Triangulo::get_base() { return this->_base; };
void Triangulo::set_base(int base) { this->_base = base; };
int Triangulo::get_altura() { return this->_altura; };
void Triangulo::set_altura(int altura) { this->_altura = altura; };
void Triangulo::desenha()
{
    this->FiguraGeometrica::desenha();
    std::cout << ' ' << "TRIANGULO" << std::endl;
}
float Triangulo::calcula_area() { return this->_base * this->_altura / 2; }

int main()
{
    std::vector<FiguraGeometrica *> figuras;
    char opcao;
    int x, y, l1, l2, r, b, a;
    while (std::cin >> opcao && opcao != 'E')
    {
        switch (opcao)
        {
        case 'R':
        {
            std::cin >> x >> y >> l1 >> l2;
            Retangulo *r = new Retangulo(Ponto(x, y), l1, l2);
            figuras.push_back(r);
        }
        break;
        case 'C':
        {
            std::cin >> x >> y >> r;
            Circulo *c = new Circulo(Ponto(x, y), r);
            figuras.push_back(c);
        }
        break;
        case 'T':
        {
            std::cin >> x >> y >> b >> a;
            Triangulo *t = new Triangulo(Ponto(x, y), b, a);
            figuras.push_back(t);
        }
        break;
        case 'D':
        {
            for (int i = 0; i < figuras.size(); i++)
                figuras.at(i)->desenha();
        }
        break;
        case 'A':
        {
            float area = 0;
            for (int i = 0; i < figuras.size(); i++)
                area += figuras.at(i)->calcula_area();
            std::cout << std::fixed;
            std::cout.precision(2);
            std::cout << area << std::endl;
        }
        break;
        case 'E':
            break;
        }
    }
    for (int i = 0; i < figuras.size(); i++)
        delete (figuras.at(i));
    return 0;
}