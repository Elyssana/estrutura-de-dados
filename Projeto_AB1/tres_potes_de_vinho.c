#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int menor = 100;

typedef struct pote
{
    int cap;
    int qtd;
} pote;

typedef struct noLista
{
    struct noLista *prox;
    struct noArvore *endereco;
} noLista;

typedef struct noArvore
{
    struct noArvore *pai;
    pote p[3];
    noLista *filhos;
    int nivel;
} noArvore;

noArvore *criaNoArvore()
{
    noArvore *no = (noArvore *)malloc(sizeof(noArvore));
    no->pai = NULL;
    no->filhos = NULL;
    return no;
}

noLista *criaNoLista()
{
    noLista *no = (noLista *)malloc(sizeof(noLista));
    no->prox = NULL;
    no->endereco = NULL;
    return no;
}

void preencherPotes(noArvore *no, int p1, int p2, int p3)
{
    no->p[0].qtd = p1;
    no->p[1].qtd = p2;
    no->p[2].qtd = p3;
    no->p[0].cap = 8;
    no->p[1].cap = 5;
    no->p[2].cap = 3;
}

bool iguais(pote pt1[], pote pt2[])
{
    for (int i = 0; i < 3; i++)
    {
        if (pt1[i].qtd != pt2[i].qtd)
        {
            return false;
        }
    }
    return true;
}

void imprimePotes(noArvore **no)
{
    printf("%d|%d|%d\n", (*no)->p[0].qtd,
           (*no)->p[1].qtd,
           (*no)->p[2].qtd);
}

void imprimeLista(noLista **lista)
{
    if (*lista == NULL)
    {
        //printf("Lista vazia\n");
        return;
    }
    else
    {
        imprimeLista((*lista)->prox);
        printf("passo #%d: ", (*lista)->endereco->nivel);
        imprimePotes(&(*lista)->endereco);
    }
}

noLista *insereNaLista(noLista **lista, noArvore *item)
{
    noLista *aux = criaNoLista();
    aux->endereco = item;
    aux->prox = *lista;
    *lista = aux;
    return *lista;
}

bool listaContem(noLista **lista, noArvore *item)
{
    if (*lista == NULL)
    {
        return false;
    }
    else
    {
        return iguais((*lista)->endereco->p, item->p)
                   ? true
                   : listaContem((*lista)->prox, item);
    }
}

noArvore *move(noArvore *origem, int i, int j)
{
    int qtd_i = origem->p[i].qtd;
    int cap_j = origem->p[j].cap;
    int qtd_j = origem->p[j].qtd;
    int t;
    if (qtd_i < (cap_j - qtd_j))
    {
        t = qtd_i;
    }
    else
    {
        t = (cap_j - qtd_j);
    }

    noArvore *aux = criaNoArvore();
    preencherPotes(aux, origem->p[0].qtd, origem->p[1].qtd, origem->p[2].qtd);
    /* aux->p[0].qtd = origem->p[0].qtd;
    aux->p[1].qtd = origem->p[1].qtd;
    aux->p[2].qtd = origem->p[2].qtd; */
    aux->p[i].qtd = origem->p[i].qtd - t;
    aux->p[j].qtd = origem->p[j].qtd + t;
    aux->pai = origem;
    aux->nivel = origem->nivel + 1;
    //printf("lista de filhos de origem:");
    //origem->filhos =
    insereNaLista(&origem->filhos, aux);

    return aux;
}

void tamMenorCaminho(noArvore *origem, noArvore *destino, noLista **visitados, noLista **dest)
{
    if (iguais(origem->p, destino->p))
    {
        int tam = origem->nivel;

        if (tam < menor)
        {
            menor = tam;
            return;
        }

        return tam;
    }

    insereNaLista(&visitados, origem);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int qtd_i = origem->p[i].qtd;

            int cap_i = origem->p[i].cap;

            int cap_j = origem->p[j].cap;

            int qtd_j = origem->p[j].qtd;

            if ((i != j) && (qtd_i > 0) && (qtd_j < cap_j))
            {
                noArvore *aux = move(origem, i, j);

                if (!listaContem(&visitados, aux))
                {

                    tamMenorCaminho(aux, destino, &visitados, &dest);
                }
            }
        }
    }
}

void caminho(noArvore *origem, noArvore *destino, noLista **visitados, noLista **dest)
{

    if (iguais(origem->p, destino->p))
    {

        if (origem->nivel == menor)
        {
            printf("\nO menor caminho possui %d passos:\n\n", menor);

            insereNaLista(&visitados, origem);

            imprimeLista(&visitados);

            return;
        }
    }

    insereNaLista(&visitados, origem);

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            int qtd_i = origem->p[i].qtd;
            int cap_i = origem->p[i].cap;
            int cap_j = origem->p[j].cap;
            int qtd_j = origem->p[j].qtd;

            if ((i != j) && (qtd_i > 0) && (qtd_j < cap_j))
            {

                noArvore *aux = move(origem, i, j);

                if (!listaContem(&visitados, aux))
                {

                    caminho(aux, destino, &visitados, &dest);
                }
            }
        }
    }
}

int main()
{
    noArvore *origem = criaNoArvore();

    preencherPotes(origem, 8, 0, 0);

    origem->nivel = 0;

    noArvore *destino = criaNoArvore();

    preencherPotes(destino, 4, 4, 0);

    noLista *visitados = NULL;

    noLista *dest = NULL;

    tamMenorCaminho(origem, destino, &visitados, &dest);

    caminho(origem, destino, &visitados, &dest);
}