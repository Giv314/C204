#include <iostream>
using namespace std;


int main()
{

    int vetor[3]; // Todo vetor eh ponteiro
    int *p;

    vetor[0] = 4;
    vetor[1] = -2;
    vetor[2] = 7;
    p = vetor;

    cout << *p << endl;
    *p++; // Desloca pra direita equivalente a 1 inteiro
    cout << *p << endl;

    return 0;
}
