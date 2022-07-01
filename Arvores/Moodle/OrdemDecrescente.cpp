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

void OrdemDecrescente (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		OrdemDecrescente(arvore->dir);
		cout << arvore->info << ' ';
		OrdemDecrescente(arvore->esq);
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
	int x; // Auxiliar para leitura dos nos

	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	// Mostra em ordem decrescente
	OrdemDecrescente(arvore);
	// Destrui a arvore
	tDestruir(arvore);

		return 0;
}