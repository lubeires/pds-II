#include <iostream>

using namespace std;

int main()
{
    bool palindromo = true;
    string texto = "";
    getline(cin, texto);
    int tam = texto.length();
    for (int i = 0; i < tam / 2; i++)
        if (texto[i] != texto[tam - 1 - i])
        {
            palindromo = false;
            break;
        }
    cout << (palindromo ? "SIM" : "NAO") << endl;
    return 0;
}