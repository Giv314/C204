#include <iostream>
using namespace std;

// Definindo struct
struct notas{
float n1; // nota1
float n2; // nota2
float n3; // nota3
float n4; //nota4
float md; //media
};


int main(){
    int i; // Contador
    // Declarando ponteiro
    notas *p = NULL;
    // Alocando memoria
    p = new notas;
    // Lendo as 4 notas
    cin >> p->n1;
    cin >> p->n2;
    cin >> p->n3;
    cin >> p->n4;
    // Calculando a media
    p->md = (p->n1 + p->n2 + p->n3 + p->n4)/4;
    // Mostrando a media
    cout << p-> md << endl;
    // Deletando variaveis na heap
    delete p;

}
