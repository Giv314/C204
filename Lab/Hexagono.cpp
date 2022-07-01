#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct ponto{
	float x; // Coordenada x do ponto
	float y; // Coordenada y do ponto
};
typedef ponto vetor;

vetor cria_vetor(ponto A, ponto B){
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B){
	float resultado;
	resultado = A.x*B.y - A.y*B.x;
	return resultado; 
}

float area_triangulo(ponto A, ponto B, ponto C){
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC))/2;
	return area;
}

float area_poligono(ponto v[], int n){
	float area = 0;
	int i = 0;
	for(i = 0; i < n-2; i++){
		area = area + area_triangulo(v[0], v[i+1], v[i+2]);
	}
	return area;
}

int main()
{
	int i; // Contador
	ponto A[6]; // Coordenadas do hexagono
	int n = 6; // Numero de lados do hexagono
	double area; // Area do hexagono
	
	for(i = 0; i<6;i++){
		cin >> A[i].x;
		cin >> A[i].y;
	}
	area = area_poligono(A, n);
	cout << "Area do escudo: " <<  fixed << setprecision(2) << area << endl; 
    return 0;
}
