#include <iostream>
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



int tRemove(treenodeptr &raiz, int x)
{
	treenodeptr p;
	if (raiz == NULL) //  ´arvore vazia
		return 1;
	if (x == raiz->info)
	{
		p = raiz;
		if (raiz->esq == NULL) // a raiz n~ao tem filho esquerdo
			raiz = raiz->dir;
		else if (raiz->dir == NULL) // a raiz n~ao tem filho direito
			raiz = raiz->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;
		return 0;
	}
	else if (x < raiz->info)
		return tRemove(raiz->esq, x);
	else
		return tRemove(raiz->dir, x);
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
	int num; // Numero a ser removido da arvore
	int rem; // 0 - Não Removeu tudo, 1 - Removeu tudo

	cin >> x;
	while(x != 0)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	cin >> num;

	rem = tRemove(arvore, num);
	while(rem != 1)
	{
		rem = tRemove(arvore, num);
	}
	emOrdem(arvore);
	
	// Destruindo a arvore para liberar memoria
	tDestruir(arvore);

	return 0;
}
