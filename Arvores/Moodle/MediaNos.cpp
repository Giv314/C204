#include <iostream>
#include <iomanip>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr;

treenodeptr tMenor(treenodeptr &raiz)
{
	treenodeptr t;
	t = raiz;
	if (t->esq == NULL) // encontrou o menor valor
	{
		raiz = raiz->dir;
		return t;
	}
	else // continua a busca na sub ´arvore esquerda
		return tMenor(raiz->esq);
}

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

void contaPreOrdem (treenodeptr arvore, int &n)
{
	if (arvore != NULL)
	{
		n++;
		contaPreOrdem(arvore->esq, n);
		contaPreOrdem(arvore->dir, n);
	}
}

void preOrdem (treenodeptr arvore, int &num2)
{
	if (arvore != NULL)
	{
		num2 += arvore->info;
		preOrdem(arvore->esq, num2);
		preOrdem(arvore->dir, num2);
	}
}

int contaNos(treenodeptr arvore)
{
	int n = 0; // numero de nos da arvore
	contaPreOrdem(arvore, n);
	return n;
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
	float num = 0; // Conta nos da arvore
	int num2 = 0; //Soma dos nos 
	float res; // Media dos elementos

	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	num = contaNos(arvore);
	preOrdem(arvore, num2);

	// Calculando a media
	res = num2/num;
	cout << "Media: " << fixed << setprecision(2) << res << endl;
	// Destruindo arvore 
	tDestruir(arvore);

		return 0;
}
