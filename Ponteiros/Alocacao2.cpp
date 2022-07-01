#include <iostream>
#include <iomanip>
using namespace std;

// Definindo struct
struct notas
{
    float n1; // nota1
    float n2; // nota2
    float n3; // nota3
    float n4; //nota4
    float md = 0; //media de cada aluno
};


int main()
{
    int i; // Contador
    int n; // Numero de alunos
    float media = 0; // Media dos n alunos
    notas *p; // Ponteiro
    // Lendo o numero de alunos
    cin >> n;
    // Criando o vetor da struct
    p = new notas[n];
    // Lendo as notas de cada aluno
    for(i = 0; i < n; i++)
    {
        cin >> p[i].n1;
        cin >> p[i].n2;
        cin >> p[i].n3;
        cin >> p[i].n4;
    }
    // Calculando a media dos alunos
    for(i = 0; i < n; i++)
    {
        p[i].md = (p[i].n1 + p[i].n2 + p[i].n3 + p[i].n4)/4;
    }
    for(i = 0; i < n; i++){
        media += p[i].md;
    }
    media /= n;
    // Mostrando a media da media dos alunos
    cout << fixed << setprecision(2) << media << endl;
    // Deletando valores na memoria heap
    delete p;
}
