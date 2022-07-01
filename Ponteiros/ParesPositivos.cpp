#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n; // Quantidade de numeros
    int *p; //Ponteiro
    int vetor[50]; // vetor
    int i; // Contador
    int quant = 0; // Quantidade de valores pares e positivos

    p = vetor;
    cin >> n;
    for(i = 0; i<n; i++){
        cin >> p[i];
        if(p[i] > 0 && p[i] % 2 == 0)
            quant ++;
    }
    // Mostra quantos valores pares e positivos tem no vetor
    cout << quant << endl;

    return 0;
}
