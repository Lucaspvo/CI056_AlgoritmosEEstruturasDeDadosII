#include <stdio.h>
#define MAX 100

void Troca (int V[], int a, int b)
{	int aux;
	aux = V[a];
	V[a] = V[b];
	V[b] = aux;
}

int  Minimo (int V[], int a3, int b3)
{	int m;
	if (a3==b3)
		return a3;
	m = Minimo (V, a3, b3-1);
	if (V[b3]<V[m])
			m=b3;
	printf ("retornei minimo\n");  
	return m;
}

int  Select (int V[], int a2, int b2)
{	int min;
	if (a2>=b2) {
		printf ("retornei 1\n");
		return 1;
	}
	printf ("entrando no troca\n");
	min = Minimo (V,a2,b2);
	Troca (V, a2, min);
    Select(V,a2+1,b2);
}

void LerVetores (int Vet[],int tam)
{	int i;
	printf ("Digite os elementos do vetor: \n");
	for (i=0; i<=tam; i++)
		scanf ("%d", &Vet[i]);
}

void ImprimirVetores (int V[], int b)
{	int i;
	printf ("O vetor ordenado e: \n");
	for (i=0; i<=b; i++)
		printf ("%d ", V[i]);
	printf ("\n");
}


	int main ()
	{
		int a=0, b, V[MAX];
		printf("Digite o tamanho do vetor: ");
		scanf("%d", &b);
		b--;
		LerVetores(V, b);
		Select(V,a, b);
		ImprimirVetores(V, b);
	}
