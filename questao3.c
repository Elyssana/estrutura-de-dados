#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct validade
{
    int data;
    int mes;
    int ano;
} data;

typedef struct regProduto
{
    int cod;
    char descricao[30];
    char marca[30];
    data data_validade;
    int quantidade;
} prod;



bool criar(no *lista)
{

    lista = (no *)malloc(sizeof(no));

    if (lista == NULL)
    {
        return false;
    }
    else
    {
        lista->prox = NULL;
        return true;
    }
}

no *inserirInicio(no *lista)
{
    printf("\n****insira um produto****\n");

    printf("digite: \nCódigo, Descrição, Marca, Validade(apenas numeros), Quantidade\n");

    no *aux;

    aux = malloc(sizeof(no));
    // criar(aux);

    
    fscanf(stdin, "%d ", &aux->dados.cod);
    fgets(aux->dados.descricao, 30, stdin);
    fgets(aux->dados.marca, 30, stdin);
    fscanf(stdin, "%2d", &aux->dados.data_validade.data);
    fscanf(stdin, "%2d", &aux->dados.data_validade.mes);
    fscanf(stdin, "%4d", &aux->dados.data_validade.ano);
    fscanf(stdin, "%d", &aux->dados.quantidade);

    aux->prox = lista;

    return aux;
}

void imprimirProduto(no *lista)
{

    if (lista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("código: %d\n", lista->dados.cod);
        printf("descricao : %s", lista->dados.descricao);
        printf("marca: %s", lista->dados.marca);
        printf("data_validade: %d/%d/%d\n", lista->dados.data_validade.data,
               lista->dados.data_validade.mes,
               lista->dados.data_validade.ano);
        printf("quantidade: %d\n", lista->dados.quantidade);
        printf("\n**********************************\n");
    }
}

void listar(no *lista)
{
    printf("\n****Listando estoque****\n");

    if (lista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        while (lista != NULL)
        {
            imprimirProduto(lista);

            lista = lista->prox;
        }
    }
}

void consultar(no *lista)
{
    int codigo, qtd = 0;
    char desc[30];

    printf("\n\ndigite o código do produto a ser consultado:\n");

    fscanf(stdin, "%d", &codigo);

    if (lista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        while (lista != NULL)
        {
            if (lista->dados.cod == codigo)
            {
                imprimirProduto(lista);
                qtd += lista->dados.quantidade;
            }
            lista = lista->prox;
        }

        printf("\nQuantidade total do produto em estoque: %d\n", qtd);
    }
    return;
}

no *maisAntigo(no *lista, int codigo)
{ //acha o registro mais antigo
    no *temp;

    while (lista != NULL) //achar primeiro registro do produto
    {
        if (lista->dados.cod == codigo)
        {
            temp = lista;
            break;
        }

        lista = lista->prox;
    }

    while (lista != NULL) // verifica se tem algum registro mais antigo do mesmo produto
    {
        if (lista->dados.cod == codigo)
        {
            if (lista->dados.data_validade.ano < temp->dados.data_validade.ano) //se ano de lista for menor
            {
                temp = lista;
            }
            else if (lista->dados.data_validade.ano == temp->dados.data_validade.ano) //se for mesmo ano..
            {
                if (lista->dados.data_validade.mes < temp->dados.data_validade.mes) //.. e mes de lista menor
                {
                    temp = lista;
                }
                else if (lista->dados.data_validade.mes == temp->dados.data_validade.mes) // se mesmo mes..
                {
                    if (lista->dados.data_validade.data < temp->dados.data_validade.data) //.. e dia de lista menor
                    {
                        temp = lista;
                    }
                }
            }
        }
        lista = lista->prox;
    }

    // printf("data_validade: %d/%d/%d\n",temp->dados.data_validade.data,
    //                                         temp->dados.data_validade.mes,
    //                                         temp->dados.data_validade.ano);
    return temp;
}

no *antecessor(no *lista, no *atual)
{
    while (lista->prox != atual)
    {
        lista = lista->prox;
    }
    printf("\nretornou antecessor\n");
    return lista;
}

no* remover(no *lista)
{
    int codigo, removeQtd;

    printf("\n\ndigite o código do produto a ser removido:\n");

    fscanf(stdin, "%d", &codigo);

    if (lista == NULL)
    {
        printf("Lista vazia!!\n");
    }
    else
    {
        no *antigo = maisAntigo(lista, codigo);

        antigo->dados.quantidade -= 1;

        no *ant = antecessor(lista, antigo);


        if (antigo->dados.quantidade == 0)
        {

            if(ant != NULL){

                ant->prox = antigo->prox;
            }
            
            free(antigo);
        }
    }
    return lista;
}

int main()
{

    
    no *lista;

    criar(lista);

    // Adicionar produtos
    lista = inserirInicio(lista);
    lista = inserirInicio(lista);
    lista = inserirInicio(lista);

    // Listar estoque
    listar(lista);

    // Consultar produtos
    consultar(lista);

    // Retirar produto
    lista = remover(lista);

    // Listar estoque

    listar(lista);
    
}