#include <iostream>
using namespace std;

int potencia(int a, int n)
{

    if(n == 0) // Condicao de parada
        return 1;
    if(n > 0)
        return a*potencia(a, n-1); // Funcao recursiva
}

int main()
{
    int a; // base
    int n; // expoente
    cin >> a >> n; // Entrada de dados
    cout << potencia(a, n) << endl;

}
