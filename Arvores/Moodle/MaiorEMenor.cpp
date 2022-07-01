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
	else 
	if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

treenodeptr pMenor(treenodeptr &arvore)
{
	treenodeptr menor;
	menor = arvore;	
	if(arvore->esq == NULL){
		 arvore = arvore->dir;
		 return menor;
	}
	else // Continua busca na subarvore esquerda
	{
		return pMenor(arvore->esq);
	}
}

treenodeptr pMaior(treenodeptr arvore)
{
	treenodeptr maior;
	maior = arvore;	
	if(arvore->dir == NULL){
		 arvore = arvore->esq;
		 return maior;
	}
	else // Continua busca na subarvore esquerda
	{
		return pMaior(arvore->dir);
	}
}

int main()
{
	int n; // Numero que sera colocado na arvore
	treenodeptr maior = NULL; // Maior elemento
	treenodeptr menor = NULL;  // Menor elemento
	treenodeptr arvore = NULL;
	cin >> n;
	while(n != -1){
		tInsere(arvore, n);
		cin >> n;
	}
	menor = pMenor(arvore);
	maior = pMaior(arvore);
	cout << menor->info << " e " << maior->info << endl;

	return 0;
}
