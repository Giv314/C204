#include <iostream>
using namespace std;

int fib(int n){
if(n == 0 || n == 1) // Condicao de parada
return 1;
else // Chamada recursiva
    return fib(n-1) + fib(n-2);
}

int main(){
int n;
    cin >> n;
    cout << fib(n) << endl;

}
