/*3 atividade) Faça um programa de gerenciamento do estoque de produtos de uma fábrica com uma lista. Considerando que o registro dos produtos no estoque contenha as seguintes informações: código, descrição, marca, data de validade e quantidade. Espera-se com este programa poder listar na tela um relatório do estoque atual, incluir, retira e consultar produtos do estoque. Lembre-se que a operação de retirada deve priorizar a saída dos produtos mais antigos e só depois dos produtos mais novos, para evitar a perda de produto por prazo de validade.

(observação você vai precisar de uma struct para definir o produto, observe que como temos diferentes entradas de um mesmo produto é necessário que você subtraia a quantidade de produtos de uma entrada no estoque até que ela seja zero, sendo primeiro retirada as entradas com prazo de validade mais próximo e depois a com prazo de validade mais distante) */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data
{
    int dia;
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

typedef struct noLista
{
    prod dados;
    struct noLista *ant;
    struct noLista *prox;
} no;

//TODO cria lista
bool criar(no **lista)
{

    *lista = (no *)malloc(sizeof(no));

    if (*lista == NULL)
    {
        return false;
    }

    else
    {
        (*lista)->prox = NULL;
        (*lista)->ant = NULL;
        return true;
    }
}

//TODO inserir produto
bool inserir(no **lista)
{
    printf("\n****insira um produto****\n");

    //printf("digite: \nCódigo\n Descrição\n Marca\n Validade(apenas numeros)\n Quantidade\n");

    no *aux;

    //aux = malloc(sizeof(no));
    criar(&aux);

    printf("Digite o código do produto:\n");
    fscanf(stdin, "%d", &aux->dados.cod);
    getchar();

    printf("Digite a descrição do produto:\n");
    fgets(aux->dados.descricao, 30, stdin);

    printf("Digite o marca do produto:\n");
    fgets(aux->dados.marca, 30, stdin);

    printf("Digite a validade do produto (apenas numeros):\n");

    fscanf(stdin, "%2d", &aux->dados.data_validade.dia);
    fscanf(stdin, "%2d", &aux->dados.data_validade.mes);
    fscanf(stdin, "%4d", &aux->dados.data_validade.ano);

    printf("Digite a quantidade:\n");
    fscanf(stdin, "%d", &aux->dados.quantidade);

    aux->prox = *lista;
    aux->ant = NULL;
    *lista = aux;
}

//TODO imprime produto
void imprimirProduto(no *lista)
{

    if (lista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("código: %d\n", (lista)->dados.cod);
        printf("descricao : %s", (lista)->dados.descricao);
        printf("marca: %s", (lista)->dados.marca);
        printf("data_validade: %d/%d/%d\n", (lista)->dados.data_validade.dia,
               (lista)->dados.data_validade.mes,
               (lista)->dados.data_validade.ano);
        printf("quantidade: %d\n", (lista)->dados.quantidade);
        printf("\n**********************************\n");
    }
}

//TODO listar estoque
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

//TODO Consultar
void consultar(no *lista)
{
    int codigo, qtd = 0;
    //char desc[30];

    printf("\n\ndigite o código do produto a ser consultado:\n");

    fscanf(stdin, "%d", &codigo);
    //getchar();

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

        printf("\nQuantidade total do produto em estoque: %d\n\n", qtd);
    }
    return;
}

no *acharAntigo(no *lista, int codigo) //acha o registro mais antigo
{
    printf("entrou no achar antigo");

    no *aux;

    while (lista != NULL) //achar primeira ocorrencia do produto na lista
    {
        if ( lista->dados.cod == codigo)
        {

            aux = lista;

            break;
        }

        lista = lista ->prox;
    }

    while (lista != NULL) // verifica se tem algum registro mais antigo do mesmo produto
    {
        if (lista->dados.cod == codigo)
        {
            if (lista->dados.data_validade.ano < aux->dados.data_validade.ano) //se ano de lista for menor
            {
                aux = lista;
            }
            else if (lista->dados.data_validade.ano == aux->dados.data_validade.ano) //se for mesmo ano..
            {
                if (lista->dados.data_validade.mes < aux->dados.data_validade.mes) //.. e mes de lista menor
                {
                    aux = lista;
                }
                else if (lista->dados.data_validade.mes == aux->dados.data_validade.mes) // se mesmo mes..
                {
                    if (lista->dados.data_validade.dia < aux->dados.data_validade.dia) //.. e dia de lista menor
                    {
                        aux = lista;
                    }
                }
            }
        }
        lista = lista->prox;
    }

    imprimirProduto(aux);
    // printf("data_validade: %d/%d/%d\n",temp->dados.data_validade.data,
    //                                         temp->dados.data_validade.mes,
    //                                         temp->dados.data_validade.ano);
   // return temp;
}
//TODO Retirar produto
no *remover(no **lista)
{
    int codigo, removeQtd;

    printf("\n\ndigite o código do produto a ser removido:\n");

    fscanf(stdin, "%d", &codigo);

    if ((*lista) == NULL)
    {
        printf("Lista vazia!!\n");
    }
    else
    {
        printf("chegou aqui!");

        no *antigo = acharAntigo(*lista, codigo);

        //printf(" descriçao: %s", (antigo)->dados.descricao);
        //imprimirProduto(&antigo);
        /*antigo->dados.quantidade -= 1;

        //no *ant = antecessor(lista, antigo);

        if (antigo->dados.quantidade == 0)
        {

            /* if(ant != NULL){

                ant->prox = antigo->prox;
            }
            
            free(antigo);
        }*/
    }
    //return lista;
}

int main()
{

    no *lista = NULL;

    int opcao = 0, item;

    while (opcao != 5)
    {
        printf("**************MENU*************\n");
        printf("1 - Listar\n");
        printf("2 - Inserir\n");
        printf("3 - Remover\n");
        printf("4 - Consultar\n");
        printf("5 - Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            listar(lista);
            setbuf(stdin, NULL);
            printf("\nPress ENTER to continue...");
            getchar();

            break;

        case 2:
            inserir(&lista);
            setbuf(stdin, NULL);
            printf("\nPress ENTER to continue...");
            getchar();
            break;
        case 3:
            remover(&lista);
            setbuf(stdin, NULL);
            printf("\nPress ENTER to continue...");
            getchar();
            break;
        case 4:
            consultar(lista);
            setbuf(stdin, NULL);
            printf("\nPress ENTER to continue...");
            getchar();
        case 5:

            break;

        default:
            printf("Opcao invalida. Tente de novo.\n");

            continue;
        }
        // system("clear");
    }

    return 0;
};
