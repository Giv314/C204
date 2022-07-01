#include <iostream>
using namespace std;

int main()
{
    int i, j; // contadores
    int x; // var aux
    int cont = 0;
    int n; // tamanho do problema
    cin >> n;
    for(i=0; i<n; i++) //Parte 1 : T(n) = n
        // T(n) = n
        x = i*2;

    for(j=0; j<n; j++) //Parte 2: T(n) = n²/2
        // T(n) = n
        for(i=0; i< n; i=i+2)
        x = i*2; // T(n) = n/2

    for(j=0; j<n; j++){ //Parte 3: T(n) = nlog(n)
        i = n; // T(n) = n
        while(i>1){
            x = i*2;
            i = i/2; // T(n) = logn
        }
    }
//Dica: O que faz o algoritmo ser T(n) = logn é *= e /=
/*
    Analise de complexidade:
    1. Soma tudo
    T(n) = n + 1/2 n² + nlog(n)
    2. Joga os coeficientes fora:
    T(n) = n + n²+ n log(n)
    3. Remove tudo, menos o que mais demora:
    Analise: O(n²);
*/
    return 0;
}
