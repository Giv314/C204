#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n; // Tamanho do vetor
    int *p = NULL; // Ponteiro
    int i; // Contador
    float media = 0;

    cin >> n; // Tamanho do vetor
    p = new int [n];
    for(i = 0; i<n; i++){
        cin >> p[i];
        media += p[i];
    }

    // Calculando e mostrando a media
    media /= n;
    cout << fixed << setprecision(2) << media << endl;

    // Deletando o vetor
    delete  [] p;
    return 0;
}
