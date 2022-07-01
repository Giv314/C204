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

void preOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		cout << arvore->info << ' ';
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << ' ';
		emOrdem(arvore->dir);
	}
}

void posOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << ' ';
	}
}


int main()
{
	treenodeptr arvore = NULL; // Ponteiro para arvore
	int x; // Auxiliar para leitura de dados
	// Inserindo dados na arvore
	cin >> x;
	while(x != 0)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	// Percurso em pre ordem
	cout << "Pre-ordem:" << endl;
	preOrdem(arvore);
	cout << endl;
	// Percurso em ordem
	cout << "Em-ordem:" << endl;
	emOrdem(arvore);
	cout << endl;
	// Percurso em pos ordem
	cout << "Pos-ordem:" << endl;
	posOrdem(arvore);

	return 0;
}
