//Aluna: Elyssana Maria 
//Compilador: gcc

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int mov = 0;

typedef struct pilha
{
    int topo;
    int discos[MAX];
} pilha;

bool pilha_vazia(pilha *pilha)
{
    return pilha->topo == -1;
}

pilha *cria_pilha()
{
    pilha *nova_pilha = (pilha *)malloc(sizeof(pilha));

    nova_pilha->topo = -1;

    return nova_pilha;
}

void empilha(pilha *pilha, int item)
{
    if (pilha->topo + 1 >= MAX)
    {
        printf("pilha Cheia!");
    }
    else
    {
        pilha->topo++;

        pilha->discos[pilha->topo] = item;
        //printf(" topo = %d\n", pilha->topo);
    }
}

int desempilha(pilha *pilha)
{
    if (pilha->topo == -1)
    {
        printf("Pilha vazia!\n");
    }
    else
    {
        int aux = pilha->discos[pilha->topo];

        pilha->discos[pilha->topo] = 0;

        pilha->topo--;

        return aux;
    }
}

void imprime_pilha(pilha *pilha)
{
    for (int i = 0; i <= pilha->topo; i++)
    {
        printf("%d ", pilha->discos[i]);
    }
}

pilha *ler_discos(pilha *torres[])
{
    int i = 0;
    int qtd_discos;
    int disco;

    while (i < 3)
    {
        printf("Quantos discos você quer inserir na %dª torre?\n>", i + 1);

        scanf("%d", &qtd_discos);

        //TODO verificar se qtd especificada está disponivel

        if (qtd_discos > 0)
        {
            printf("Digite os discos da %dª torre:\n>", i + 1);
        }

        while (qtd_discos > 0)
        {
            scanf("%d", &disco);

            //TODO verificar se numero digitado é valido(*entre 1 e 5, *não foi digitado antes, * se menor que o anterior da pilha)

            empilha(torres[i], disco);

            qtd_discos--;
        }

        i++;
    }
}

pilha *imprimir_torres(pilha *torres[])
{
    int i = 0;

    while (i < 3)
    {
        printf("Torre %d -> ", i + 1);

        imprime_pilha(torres[i]);

        printf("\n");

        i++;
    }
    printf("\n*************************\n");
}

int torre_do_disco(pilha *torres[], int disco)
{
    int i = 0;
    int j = 0;


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= torres[i]->topo; j++)
        {
            if (torres[i]->discos[j] == disco)
            {
                return i;
            }
        }
    }
}

int torre_aux(int orig, int dest)
{
    if (orig == 0)
    {
        return dest == 1 ? 2 : 1;
    }
    else if (orig == 1)
    {
        return dest == 0 ? 2 : 0;
    }
    else if (orig == 2)
    {
        return dest == 0 ? 1 : 0;
    }
}

int move(pilha *torres[], int orig, int dest)
{
    int disco = desempilha(torres[orig]);

    empilha(torres[dest], disco);
}

pilha *resolve_torre(pilha *torres[], int n, int orig, int dest)
{
    if (n >= 1)
    {
        int origProx = torre_do_disco(torres, n - 1);

        int aux = torre_aux(orig, dest); //

        resolve_torre(torres, n - 1, origProx, aux);

        if (orig != dest)
        {
            move(torres, orig, dest);
            
            printf("Movimento %d:\n", ++mov);

            imprimir_torres(torres);
        }

        int auxProx = torre_aux(aux, dest);

        origProx = torre_do_disco(torres, n - 1);

        resolve_torre(torres, n - 1, origProx, dest);
    }
}

int main()
{

    pilha *torre[3];

    torre[0] = cria_pilha();
    torre[1] = cria_pilha();
    torre[2] = cria_pilha();

    ler_discos(torre);

    imprimir_torres(torre);

    int dest = torre_do_disco(torre, MAX);

    int orig = torre_do_disco(torre, MAX - 1);

    resolve_torre(torre, MAX - 1, orig, dest);
}