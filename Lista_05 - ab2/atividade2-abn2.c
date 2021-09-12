/*Linguagem utilizada: C;

Aluna: Elyssana Maria da Silva Oliveira;

Exercises:7.21 Counting sort (assuming the input key values are integers in the range 0 to m− 1) works by counting the number of records with each key value in the first pass, and then uses this information to place the records in order in a second pass. Write an implementation of counting sort (see the implementa- tion of radix sort for some ideas)*/

#include <stdio.h>
#include <string.h>

void imprimeVetor(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

int max(int array[], int tam)
{

    int max = 0;

    for (int i = 0; i < tam; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

int countingSort(int sort[], int n)
{
    int k = max(sort, n);

    int aux[++k];

    for (int i = 0; i < k; i++)
    {
        aux[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        aux[sort[i]]++;
    }

    printf("\naux: ");
    imprimeVetor(aux, k);

    int j = 0;

    for (int i = 0; i < k; i++)
    {
        while (aux[i] != 0)
        {
            sort[j] = i;
            aux[i]--;
            j++;
        }
    }
}

int main()
{
    int n;

    printf("digite a quantidade de numeros a serem ordenados:\n>");
    
    scanf("%d", &n);

    int array[n];

    printf("Digite os números a serem ordenados:\n>");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nentrada: ");
    imprimeVetor(array, n);

    countingSort(array, n);

    printf("\nsaida: ");
    imprimeVetor(array, n);
}