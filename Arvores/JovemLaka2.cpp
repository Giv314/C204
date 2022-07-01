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

void preOrdem (treenodeptr &arvore, int n, int &cont, int &achou)
{
	if(arvore != NULL)
	{
		if(arvore->info == n)
			achou = cont;
		cont++;
		preOrdem(arvore->esq, n, cont, achou);
		preOrdem(arvore->dir, n, cont, achou);
	}
}

void emOrdem (treenodeptr arvore, int &n, int &cont, int &achou)
{
	if(arvore != NULL)
	{
		emOrdem(arvore->esq, n, cont, achou);
		if(arvore->info == n)
			achou = cont;
		cont++;
		emOrdem(arvore->dir, n, cont, achou);
	}
}

void posOrdem (treenodeptr arvore, int n, int &cont, int &achou)
{
	if(arvore != NULL)
	{
		posOrdem(arvore->esq, n, cont, achou);
		posOrdem(arvore->dir, n, cont, achou);
		if(arvore->info == n)
			achou = cont;
		cont++;
	}
}

int contaPreOrdem(treenodeptr arvore, int &n)
{
	int cont = 0;
	int achou = 0; // Auxiliar pra guardar a posição
	preOrdem(arvore, n, cont, achou);
	return achou;
}

int contaPosOrdem(treenodeptr arvore, int &n)
{
	int cont = 0;
	int achou = 0;
	posOrdem(arvore, n, cont, achou);
	return achou;
}

int contaEmOrdem(treenodeptr arvore, int &n)
{
	int cont = 0;
	int achou = 0;
	emOrdem(arvore, n, cont, achou);
	return achou;
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
	int cpre; // Contador pre ordem
	int cpos = 0; // Contador em ordem
	int cem = 0; // Contador pos ordem
	// Inserindo dados na arvore

	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	cin >> n;
	// Percurso nas ordens
	cpre = contaPreOrdem(arvore, n);
	cpos = contaPosOrdem(arvore, n);
	cem = contaEmOrdem(arvore, n);

	// Comparando contadores
	if(cpre < cpos && cpre < cem)
		cout << "Pre" << endl;
	else if(cpos < cpre && cpos < cem)
		cout << "Pos" << endl;
	else
		cout << "Em" << endl;

	cout << endl;
	// Destruindo arvore
	tDestruir(arvore);

	return 0;
}
