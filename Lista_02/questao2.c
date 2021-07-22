#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct fila
{
    int tam_atual;
    int prim;
    int ult;
    int itens[MAX];
} fila;

fila *cria_fila()
{
    fila *nova_fila = (fila *)malloc(sizeof(fila));

    nova_fila->tam_atual = 0;
    nova_fila->prim = 0;
    nova_fila->ult = -1;

    return nova_fila;
}

void insere_na_fila(fila *fila, int item)
{
    if (fila->tam_atual >= MAX)
    {
        printf("Fila Cheia!");
    }
    else
    {
        fila->ult += 1;
        fila->itens[fila->ult] = item;
        fila->tam_atual++;
    }
}

bool fila_vazia(fila *fila)
{
    return fila->tam_atual == 0;
}

int remove_da_fila(fila *fila)
{
    if (vazia(fila))
    {
        printf("Pilha vazia!");

        return -1;
    }
    else
    {
        int item = fila->itens[fila->prim];

        printf("\nproximo chamado: %d\n, muda isso aqui de LOGO!\n", item);

        for (int i = 0; i < fila->ult; i++)
        {
            fila->itens[i] = fila->itens[i + 1];
        }
        // fila->prim = fila->prim + 1;
        --fila->tam_atual;

        --fila->ult; //PReste tenção nisso AQUI!!

        return item;
    }
}

void imprime_fila(fila *fila)
{
    for(int i = 0; i < fila->tam_atual; i++)
    {
        printf("%d ", fila->itens[i]);
    }
    printf("\n");
    /* int i = 0;

    while (i < fila->tam_atual)
    {
        printf("%d ", fila->itens[i]);
        i++;
    }
    printf("\n"); */
}
   
int chamar_próximo(){

}


