#include <iostream>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

void emOrdem (treenodeptr arvore, int n, int v[], int &c1)
{
	int i = 0;
	if (arvore != NULL)
	{
		emOrdem(arvore->esq, n, v, c1);
		v[i] = arvore->info;
		cout << "v[i] fora = " << v[i] << ' ';
		cout << endl;
		cout << "i fora: " << i << ' ';
		cout << endl;
		if(v[i] == n)
		{
			cout <<" v[i] no if = " << v[i] << endl;
			cout << "i: " << i << endl;
			c1 = i;
			cout << c1 << endl;
		}
		i++; // Aqui esta o problema
		emOrdem(arvore->dir, n, v, c1);
	}
}

void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	treenodeptr arvore = NULL; // Ponteiro para arvore
	int x; // Auxiliar para leitura de dados
	int n; // Numero desejado
	int vpre[30]; // Vetor para pre ordem
	int vpos[30];
	int vem[30]; // Vetor para em ordem
	int c1; // Diz onde a cidade esta
	int j = 0; // Contador

	cin >> x;
	while(x != -1)
	{
		j++;
		tInsere(arvore, x);
		cin >> x;
	}
	cin >> n;
	emOrdem(arvore, n, vem, c1);
	cout << c1 << endl;
	// Destruindo arvore
	tDestruir(arvore);

}
