#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n; // Quantidade de numeros
    int *p; //Ponteiro
    int vetor[50]; // vetor
    int i; // Contador
    int maxval = -1000;

    p = vetor;
    cin >> n;
    for(i = 0; i<n; i++){
        cin >> p[i];
        if(p[i] > maxval)
            maxval = p[i];
    }
    // Mostra o valor maximo
    cout << maxval << endl;

    return 0;
}
