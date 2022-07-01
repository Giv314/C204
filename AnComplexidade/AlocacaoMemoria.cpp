#include <iostream>
using namespace std;

struct dado
{
    int info1;
    int info2;
};

int main()
{

    dado *produto = NULL;
    produto = new dado; // New cria a struct
    produto->info1 = 2;
    produto->info2 = 3;

    cout << produto->info1 << endl;
    cout << produto->info2 << endl;

    delete produto;

    return 0;
}
