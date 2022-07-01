#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

float raiz(float x, float xo, float e)
{
    if(abs(pow(xo, 2) - x) <= e) // Condicao de parada
        return xo;
    else
        return raiz(x, (pow(xo, 2) + x)/(2*xo), e); // Recursiva
}


int main()
{
    float x; // numero que deseja calcular
    float xo; // estimativa
    float e; // Precisão
    cin >> x >> xo >> e;
    cout << fixed << setprecision(4) << raiz(x, xo, e) << endl;

}
