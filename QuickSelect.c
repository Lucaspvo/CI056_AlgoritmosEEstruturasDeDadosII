#include <stdio.h>

#define MAX 100
#define K 3

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
  			Troca (V,i,j);
			ImprimirVetores (V, b);			
		}
	}
	return i;
}

int  Minimo (int V[], int a3, int b3)
{	int m;
	if (a3==b3)
		return a3;
	m = Minimo (V, a3, b3-1);
	if (V[b3]<V[m])
			m=b3; 
	return m;
}

int  Select (int V[], int a2, int b2)
{	int min;
	if (a2>=b2) {
		return 1;
	}
	min = Minimo (V,a2,b2);
	Troca (V, a2, min);
	ImprimirVetores (V, b2);
	printf ("por selecao k=%d a=%d b=%d\n",K,a2,b2);
    Select(V,a2+1,b2);
}
 
int  QuickSelect (int V[], int a1, int b1)
{ 	int m;
	printf ("k=%d a=%d b=%d\n",K,a1,b1);
  	if (b1-a1+1 < K) {
     		Select (V,a1,b1);
	}
	else
	{
		m= Partition (V, a1, b1);
	  	QuickSelect (V, a1, m-1);
	  	QuickSelect (V, m+1, b1);
	}
}  

int main ()
{	int V[MAX], a=0,b;
	printf ("Digite o tamanho do vetor: \n");
	scanf  ("%d", &b);
	b--;
	LerVetores (V,b);
	QuickSelect (V, a, b);
	ImprimirVetores (V, b);
}
