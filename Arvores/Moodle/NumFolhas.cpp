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

void contaPreOrdem(treenodeptr arvore, int &n)
{
	if(arvore != NULL){
		contaPreOrdem(arvore->esq, n);
		if(arvore->esq == NULL && arvore->dir == NULL){
		n++;
		}
		contaPreOrdem(arvore->dir, n);
	}
	
}

void contaFolhas(treenodeptr arvore, int &n)
{
	contaPreOrdem(arvore, n);
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
	int n = 0; // Numero de folhas da arvore

	// Inserindo dados na arvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	
	// Contando Folhas
	contaFolhas(arvore, n);
	cout << "Numero de folhas: " << n << ' ';
	cout << endl;

	// Destruindo arvore 
	tDestruir(arvore);

	return 0;
}
