#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in("palavras.txt", fstream::in);
    if (!in.is_open())
        return 1;

    int n, c;
    in >> n;

    string palavras[n];
    for (int i = 0; i < n; i++)
        in >> palavras[i];

    cin >> c;

    string tentativa, retorno, letrasNaoPresentes = "", chave = palavras[c - 1];
    bool ganhou = false;

    for (int i = 0; i < 5; i++)
    {
        retorno = "";
        cin >> tentativa;
        for (int j = 0; j < 5; j++)
        {
            char letra = tentativa[j];
            if (letra == chave[j])
                retorno += letra;
            else if (chave.find(letra) != string::npos)
                retorno += tolower(letra);
            else
            {
                retorno += '*';
                if (letrasNaoPresentes.find(letra) == string::npos)
                    letrasNaoPresentes += letra;
            }
        }
        cout << retorno << " (" << letrasNaoPresentes << ")" << endl;
        if (tentativa.compare(chave) == 0)
        {
            ganhou = true;
            break;
        }
    }

    cout << (ganhou ? "GANHOU!" : "PERDEU! " + chave) << endl;
    in.close();
    return 0;
}