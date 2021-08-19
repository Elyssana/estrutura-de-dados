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

noLista *criaNoLista(n)
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
        //printf("%d e %d\n", pt1[i].qtd, pt2[i].qtd);
        if (pt1[i].qtd != pt2[i].qtd)
        {
            //printf("não é igual\n");
            return false;
        }
    }
    //printf("é igual\n");
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
        printf("Lista vazia\n");
        return;
    }
    else
    {
        //printf("entrou no else\n");
        imprimeLista((*lista)->prox);
        //printf("Lista não ta vazia\n");
        imprimePotes(&(*lista)->endereco);
    }
}
noLista *insereNaLista(noLista **lista, noArvore *item)
{
    //imprimePotes(item);
    noLista *aux = criaNoLista();
    aux->endereco = item;
    //printf("inseriu\n");
    aux->prox = *lista;
    *lista = aux;
    //imprimePotes(&aux);
    //printf("-----lista\n");
    //imprimeLista(&lista);
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
    //!!!!!!!!!printf("entrou no move() i=%d j=%d\n", i, j);
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

    //!!!!!!!!!printf("t = %d\n", t);

    //TODO função inserirNaArvore()

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

int tamLista(noLista *lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + tamLista(lista->prox);
    }
}

void tamMenorCaminho(noArvore *origem, noArvore *destino, noLista **visitados, noLista **dest)
{
    //!!!!!!!!!printf("entrou no potesDeVinhos origem valendo = ");
    //imprimePotes(&origem);

    if (iguais(origem->p, destino->p))
    {
        //imprimePotes(&destino);
        int tam = origem->nivel;

        printf("\ntam = %d", tam);
        if (tam < menor)
        {
            menor = tam;
            return;
        }

        /*insereNaLista(&visitados, origem);
        insereNaLista(&dest, origem);
        tamM/menorCaminhporaiz, destino, raiz, &visitados, &dest);
        imprimeLista(&visitados);*/

        return tam;
    }

    //*visitados =

    insereNaLista(&visitados, origem);

    //!!!!!!!!!printf("---lista visitados:\n");

    //imprimeLista(&visitados);
    //int tam = 0;
    for (int i = 0; i < 3; i++)
    {
        // printf("entrou no for i = %d\n", i);
        for (int j = 0; j < 3; j++)
        {
            //printf("entrou no for jota = %d\n", j);
            //printf("i = %d, j = %d\n", i, j);
            int qtd_i = origem->p[i].qtd;

            int cap_i = origem->p[i].cap;

            int cap_j = origem->p[j].cap;

            int qtd_j = origem->p[j].qtd;

            //printf("qtd_i=%d, cap_i=%d, qtd_j=%d, cap_j=%d\n", qtd_i, cap_i, qtd_j, cap_j);

            if ((i != j) && (qtd_i > 0) && (qtd_j < cap_j))
            {
                //!!!!!!!!!printf("entrou no if (diferent, não vazio e não cheio)\n");

                /* int t = qtd_i < (cap_j - qtd_j)
                            ? qtd_i
                            : (cap_j - qtd_j);
                printf("t = %d\n", t);

                //TODO função inserirNaArvore()
                noArvore *aux = criaNoArvore();
                aux->p[0].qtd = origem->p[0].qtd;
                aux->p[1].qtd = origem->p[1].qtd;
                aux->p[2].qtd = origem->p[2].qtd;
                aux->p[i].qtd = origem->p[i].qtd - t;
                aux->p[j].qtd = origem->p[j].qtd + t;
                aux->pai = origem;
                aux->nivel = origem->nivel + 1;
                origem->filhos = insereNaLista(origem->filhos, aux); */
                noArvore *aux = move(origem, i, j);

                //!!!!!!!!!printf("origem: ");
                //!!!!!!!!!imprimePotes(&origem);
                //!!!!!!!!!printf("aux: ");
                //!!!!!!!!!imprimePotes(&aux);
                //!!!!!!!!!printf("\n");

                if (!listaContem(&visitados, aux))
                {

                    //!!!!!!!!!printf("aux  ainda não havia sido visidtado\n");
                    tamMenorCaminho(aux, destino, &visitados, &dest);
                    //!!!!!!!!!printf("voltou!\n");
                    //return; //visitados;
                }
            }
        }
    }
    //printf("\ntam = %d", tam);
    //return menor;
}

void caminho(noArvore *origem, noArvore *destino, noLista **visitados, noLista **dest)
{
    //!!!!!!!!!printf("entrou no potesDeVinhos origem valendo = ");
    //imprimePotes(&origem);

    if (iguais(origem->p, destino->p))
    {
        //imprimePotes(&destino);

        /*printf("\ntam = %d", tam);*/
        if (origem->nivel == menor)
        {
            printf("nivel = %d e menor = %d", origem->nivel, menor);
            insereNaLista(&visitados, origem);
            //insereNaLista(&dest, origem);
            //tamM/menorCaminhporaiz, destino, raiz, &visitados, &dest);
            imprimeLista(&visitados);

            return;
        }

        //return tam;
    }

    //*visitados =

    insereNaLista(&visitados, origem);

    //!!!!!!!!!printf("---lista visitados:\n");

    //imprimeLista(&visitados);
    //int tam = 0;
    for (int i = 0; i < 3; i++)
    {
        // printf("entrou no for i = %d\n", i);
        for (int j = 0; j < 3; j++)
        {
            //printf("entrou no for jota = %d\n", j);
            //printf("i = %d, j = %d\n", i, j);
            int qtd_i = origem->p[i].qtd;

            int cap_i = origem->p[i].cap;

            int cap_j = origem->p[j].cap;

            int qtd_j = origem->p[j].qtd;

            //printf("qtd_i=%d, cap_i=%d, qtd_j=%d, cap_j=%d\n", qtd_i, cap_i, qtd_j, cap_j);

            if ((i != j) && (qtd_i > 0) && (qtd_j < cap_j))
            {
                //!!!!!!!!!printf("entrou no if (diferent, não vazio e não cheio)\n");

                /* int t = qtd_i < (cap_j - qtd_j)
                            ? qtd_i
                            : (cap_j - qtd_j);
                printf("t = %d\n", t);

                //TODO função inserirNaArvore()
                noArvore *aux = criaNoArvore();
                aux->p[0].qtd = origem->p[0].qtd;
                aux->p[1].qtd = origem->p[1].qtd;
                aux->p[2].qtd = origem->p[2].qtd;
                aux->p[i].qtd = origem->p[i].qtd - t;
                aux->p[j].qtd = origem->p[j].qtd + t;
                aux->pai = origem;
                aux->nivel = origem->nivel + 1;
                origem->filhos = insereNaLista(origem->filhos, aux); */
                noArvore *aux = move(origem, i, j);

                //!!!!!!!!!printf("origem: ");
                //!!!!!!!!!imprimePotes(&origem);
                //!!!!!!!!!printf("aux: ");
                //!!!!!!!!!imprimePotes(&aux);
                //!!!!!!!!!printf("\n");

                if (!listaContem(&visitados, aux))
                {

                    //!!!!!!!!!printf("aux  ainda não havia sido visidtado\n");
                    caminho(aux, destino, &visitados, &dest);
                    //!!!!!!!!!printf("voltou!\n");
                    //return; //visitados;
                }
            }
        }
    }
    //printf("\ntam = %d", tam);
    //return menor;
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

    printf("menor = %d", menor);

    caminho(origem, destino, &visitados, &dest);
}