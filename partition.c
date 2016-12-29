#include <stdio.h>
#define MAX 100

void Troca (int V[], int a, int b)
{	int aux;
	aux = V[a];
	V[a] = V[b];
	V[b] = aux;
}

int  Partition (int V[], int a, int b) {
	int i,j;
	i=a-1;
	for (j=a;j<=b;j++) {
		if (V[j] <= V[b]) {
			i=i+1;
			printf ("%d \n", i);
  			Troca (V,i,j);
			
		}
	}
	printf("O valor de partition é %d!", i);
	return i;
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
		Partition(V,a, b);
		ImprimirVetores(V, b);
	}
	
