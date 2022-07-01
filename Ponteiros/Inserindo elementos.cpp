#include <iostream>
using namespace std;

int main()
{
    int n; // Tamanho do vetor
    int *p = NULL; // Ponteiro
    int i; // Contador

    cin >> n; // Tamanho do vetor
    p = new int [n];
    for(i = 0; i<n; i++)
        cin >> p[i];
    // Mostrando
    for(i = 0; i< n; i++)
        cout << p[i] << ' ';
cout << endl;
    // Deletando o vetor
    delete  [] p;
    return 0;
}
