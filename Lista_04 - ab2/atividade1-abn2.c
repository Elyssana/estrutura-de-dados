#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct no
{
    int item;
    struct no *esq;
    struct no *dir;
} no;

no *criaNo(int item)
{
    no *noArvore = (no *)malloc(sizeof(no));
    noArvore->item = item;
    noArvore->esq = NULL;
    noArvore->dir = NULL;

    return noArvore;
}

/* verifica se duas árvores são identicas */
bool arvoresIdenticas(struct no *arv1, struct no *arv2)
{
    /*se as duas são vazias*/
    if (arv1 == NULL && arv2 == NULL)
        return true;

    /*se nenhuma é vazia*/
    if (arv1 != NULL && arv2 != NULL)
    {
        return (arv1->item == arv2->item && ((arvoresIdenticas(arv1->esq, arv2->esq) && arvoresIdenticas(arv1->dir, arv2->dir)) ||
                                             (arvoresIdenticas(arv1->esq, arv2->dir) && arvoresIdenticas(arv1->dir, arv2->esq))));
    }

    return false;
}

no *insere(no *arv, int item)
{
    if (arv == NULL)
    {
        return criaNo(item);
    }
    else if (arv != "/")
    {
        arv->esq = insere(arv->esq, item);
    }
    else
    {
        arv->dir = insere(arv->dir, item);
    }
}

no *montarAvore(no *arv, char aux[])
{
    int i = 0;
    int tamString = strlen(aux);

    while (i < tamString)
    {
        arv = insere(arv, aux[i]);
        i++;
    }

    return arv;
}

//AB/D//CEG///FH//I//
int main()
{

    //char av1[50], av2[50];
    /*  scanf("%s", &av1);
    scanf("%s", &av2); */

    no *arv1 = criaNo(1);
    no *arv2 = criaNo(1);
    arv1->esq = criaNo(2);
    arv1->dir = criaNo(3);
    arv1->esq->esq = criaNo(4);
    arv1->esq->dir = criaNo(5);

    arv2->esq = criaNo(2);
    arv2->dir = criaNo(3);
    arv2->esq->esq = criaNo(4);
    arv2->esq->dir = criaNo(5);
    arv2->dir->esq = criaNo(6);

    if (arvoresIdenticas(arv1, arv2))
        printf("São identicas!");
    else
        printf("Não são identicas!");

    //getchar();
    return;
}