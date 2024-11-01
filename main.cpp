#include <iostream>
using namespace std;

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.
void somaUm(int val, int &ref, int *p)
{
    val++;
    ref++;
    (*p)++;
    return;
}

int main()
{
    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int n;
    cin >> n;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *p = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tam;
    cin >> tam;
    int *v = new int[tam];
    for (int i = 0; i < tam; i++)
        cin >> v[i];

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &n << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &p << endl;

    // 7) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &v << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << v << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << v[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    p = &n;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *p = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    p = v;

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    p = &v[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    cout << (p == v ? 'S' : 'N') << endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < tam; i++)
        p[i] *= 10;

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < tam - 1; i++)
        cout << v[i] << ' ';
    cout << v[tam - 1] << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (int i = 0; i < tam - 1; i++)
        cout << *(v + i) << ' ';
    cout << *(v + tam - 1) << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for (int i = 0; i < tam - 1; i++)
        cout << *(p + i) << ' ';
    cout << *(p + tam - 1) << endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    p = &v[tam - 1];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **p2 = &p;

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << p2 << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &p2 << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *p2 << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **p2 << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int a, b, c;
    cin >> a >> b >> c;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    somaUm(a, b, &c);

    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}