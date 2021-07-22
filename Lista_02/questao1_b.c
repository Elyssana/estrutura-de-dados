#include <stdio.h>
#include <string.h>

int criaPilha()
{
    int topo = -1;

    return topo;
}

int empilha(int pilha[], int topo, int elem, int max)
{
    if (topo == max)
    {
        printf("Pilha cheia!");
    }
    else
    {
        topo++;

        pilha[topo] = elem;
    }
    return topo;
}

int desempilha(int pilha[], int topo)
{
    pilha[topo] = ' ';

    topo--;

    return topo;
}

void parenteses(int topo, int i, int pilha[], char str[])
{

    if (topo < -1)
    {
        printf("1º excesso de ')' na posição: \t%d \n", i);
    }

    else if (topo > -1)
    {
        if (topo > 0)
        {
            while (topo > 0)
            {
                desempilha(pilha, topo);
                topo--;
            }
        }
        printf("1º excesso '(' na posição: \t%d \n", pilha[topo]);
    }
    else if (topo == -1)
    {
        printf("parenteses balanceados!\n");
    }
}

void verifica(char str[], int pilha[], int max)
{
    int i, topo = criaPilha();

    for (i = 0; i < max; i++)
    {
        if (str[i] == '(')
        {
            topo = empilha(pilha, topo, i, max);
        }
        else if (str[i] == ')')
        {
            topo = desempilha(pilha, topo);

            if (topo < -1)
            {

                break;
            }
        }
    }

    parenteses(topo, i, pilha, str);
}

int main()
{

    while(1)
    {
        char str[100];
        int pilha[100];

        scanf("%s", str);

        int tam = strlen(str);

        verifica(str, pilha, tam);
    }
}
