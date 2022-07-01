#include <iostream>
using namespace std;


int main() // Memoria stack
{

    float *vetor = NULL;
    int n; // tamanho desejado pro vetor
    int i; // contador

    //Lendo tamanho desejado
    cin >> n;
    // Alocando memoria pro vetor
    vetor = new float[n];
    // Lendo e inserindo elementos no vetor
    for(i = 0; i< n; i++)
        cin >> vetor[i];
    // Mostrando o vetor
    for(i = 0; i< n; i++)
        cout << vetor[i] << ' ';
    // Deletando vetor (memoria heap)
    delete [] vetor;

    return 0;
}
