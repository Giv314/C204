#include <iostream>

using namespace std;

struct item
{
	int val; // nota do brinquedo
	int peso; // tempo em minutos
};

int main()
{
	int pd[100][100]; 	// valor maximo sendo:
						// olhando do item 'i'->final
						// olhando uma mochila de capacidade 'j'

	int caminho[100][100]; 	// utilizado para recuperar quais itens foram escolhidos
							// 0 -> nao pegar o item
							// 1 -> pegar o item

	int n; // quantidade de brinquedos
	int capacidade; // tempo em minutos
	item v[100]; // vetor de brinquedos

	// Entra com o tempo em minutos totais
	cin >> capacidade;

	// Entra com a quantidade de brinquedos
	cin >> n;

	for(int i=0; i<n; i++)
	{
		 // Entra com o tempo em minutos de um brinquedo, e a nota
		cin >> v[i].peso >> v[i].val;
	}

	// CASO BASE:
	// olhando do ultimo item para frente, val. maximo = 0
	for(int j = 0; j <= capacidade; j++)
		pd[n][j] = 0;

	// olhando tendo uma mochila de capacidade 0, o val. maximo=0
	for(int i = 0; i <= n; i++)
		pd[i][0] = 0;


	// CASO GERAL
	for(int i = n - 1; i >= 0; i--)
		for(int j = 1; j <= capacidade; j++)
		{
			int pega, npega; // val. para caso eu pegar ou nao pegar o item 'i'

			npega = pd[i + 1][j]; // olhar o proximo item, mantendo a capacidade 'j'

			if(j >= v[i].peso) // se eu tiver capacidade disponivel p/ pegar o item 'i'
				pega = pd[i + 1][j - v[i].peso] + v[i].val;
			// olho o proximo item, subtraio o peso da capacidade
			// disponivel, e somo o valor do item 'i'
			else
				pega = 0; // se nao posso pegar, o valor eh 0



			if(pega > npega) // se valer a pena pegar
			{
				pd[i][j] = pega;
				caminho[i][j] = 1;
			}

			else // se valer a pena nao pegar
			{
				pd[i][j] = npega;
				caminho[i][j] = 0;
			}
		}

	cout << pd[0][capacidade] << endl;

	return 0;
}
