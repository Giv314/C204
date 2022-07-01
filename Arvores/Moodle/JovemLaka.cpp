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

void preOrdem (treenodeptr arvore, int &n, int &c1)
{
	if(arvore != NULL)
	{
		if(arvore->info != n)
		{
			c1++;
			preOrdem(arvore->esq, n, c1);
			preOrdem(arvore->dir, n, c1);
		}
	}
}

void emOrdem (treenodeptr arvore, int &n, int &c2)
{
	if(arvore != NULL)
	{
		emOrdem(arvore->esq, n, c2);
		cout << arvore-> info << ' ';
		if (arvore->info != n)
		{
			c2++;
		}
		emOrdem(arvore->dir, n, c2);
		cout << endl;
	}
}

void posOrdem (treenodeptr arvore, int &n, int &c3)
{
	if(arvore != NULL)
	{
		if (arvore->info != n)
		{
			posOrdem(arvore->esq, n, c3);
			posOrdem(arvore->dir, n, c3);
			c3++;
		}
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
	int c1 = 0; // Contador 1
	int c2 = 0; // Contador 2
	int c3 = 0; // Contador 3
	// Inserindo dados na arvore

	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	cin >> n;
	// Percurso nas ordens
	preOrdem(arvore, n, c1);
	emOrdem(arvore, n, c2);
	posOrdem(arvore, n, c3);

	// Comparando contadores
	cout << c1 << ' ' << c2 << ' ' << c3 <<  ' ' << endl;

	// Destruindo arvore
	tDestruir(arvore);

	return 0;
}
