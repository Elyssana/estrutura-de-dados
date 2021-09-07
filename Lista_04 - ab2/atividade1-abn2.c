/*Linguagem utilizada: C;

Aluna: Elyssana Maria da Silva Oliveira;

Exercises: 6.2 Write an algorithm to determine if two binary trees are identical when the
ordering of the subtrees for a node is ignored. For example, if a tree has root
node with value R, left child with value A and right child with value B, this
would be considered identical to another tree with root node value R, left
child value B, and right child value A. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct no
{
    char item;
    struct no *esq;
    struct no *dir;
} no;

no *criaNo(char item)
{
    no *noArvore = (no *)malloc(sizeof(no));
    noArvore->item = item;
    noArvore->esq = NULL;
    noArvore->dir = NULL;

    return noArvore;
}

/* verifica se duas árvores são identicas */
bool arvoresIdenticas(no *arv1, no *arv2)
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

no *insere(no *arv, char item)
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

void imprimir(no *tree)
{
    if (tree == NULL)
    {
        printf("()");
    }
    else
    {
        printf("%c", tree->item);
        printf("(");
        imprimir(tree->esq);
        imprimir(tree->dir);
        printf(")");
    }
}

int main()
{
    printf("OBS.: As árvores são inseridas de forma estática no código.\n\n");

    /*//Caso de teste 1:

    no *arv1 = criaNo('1');
    no *arv2 = criaNo('1');
    arv1->esq = criaNo('2');
    arv1->esq->esq = criaNo('3');
    arv2->dir = criaNo('2');
    arv2->dir->dir = criaNo('3');*/

    //Caso de teste 2:
    no *arv1 = criaNo('A');
    no *arv2 = criaNo('A');
    arv1->esq = criaNo('B');
    arv1->dir = criaNo('C');
    arv1->esq->esq = criaNo('D');
    arv1->esq->dir = criaNo('E');
    arv2->esq = criaNo('C');
    arv2->dir = criaNo('B');
    arv2->dir->esq = criaNo('E');
    arv2->dir->dir = criaNo('D');

    printf("Arvores(pré-ordem):\n\n1- ");
    imprimir(arv1);
    printf("\n2- ");
    imprimir(arv2);

    printf("\n\nIdenticas? ");
    if (arvoresIdenticas(arv1, arv2))
        printf("SIM!");
    else
        printf("NÃO!");

    return;
}