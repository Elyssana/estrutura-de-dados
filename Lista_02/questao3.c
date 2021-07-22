/*3 atividade) Faça um programa de gerenciamento do estoque de produtos de uma fábrica com uma lista. Considerando que o registro dos produtos no estoque contenha as seguintes informações: código, descrição, marca, data de validade e quantidade. Espera-se com este programa poder listar na tela um relatório do estoque atual, incluir, retira e consultar produtos do estoque. Lembre-se que a operação de retirada deve priorizar a saída dos produtos mais antigos e só depois dos produtos mais novos, para evitar a perda de produto por prazo de validade.

(observação você vai precisar de uma struct para definir o produto, observe que como temos diferentes entradas de um mesmo produto é necessário que você subtraia a quantidade de produtos de uma entrada no estoque até que ela seja zero, sendo primeiro retirada as entradas com prazo de validade mais próximo e depois a com prazo de validade mais distante) */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// cria Nó da lista
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

// inserir produto
bool inserirProduto(no **lista)
{
    printf("\n*****insira um produto*****\n");

    no *aux;

    criar(&aux);

    printf("Digite o código do produto:\n>>");
    fscanf(stdin, "%d", &aux->dados.cod);
    getchar();
    
    printf("Digite a descrição do produto:\n>>");
    fgets(aux->dados.descricao, 30, stdin);

    printf("Digite o marca do produto:\n>>");
    fgets(aux->dados.marca, 30, stdin);
 
    printf("Digite a validade do produto (apenas numeros):\n>>");

    fscanf(stdin, "%2d", &aux->dados.data_validade.dia);
    fscanf(stdin, "%2d", &aux->dados.data_validade.mes);
    fscanf(stdin, "%4d", &aux->dados.data_validade.ano);

    printf("Digite a quantidade:\n>>");
    fscanf(stdin, "%d", &aux->dados.quantidade);

    aux->prox = *lista;
    aux->ant = NULL;

    if (*lista != NULL)
    {
        (*lista)->ant = aux;
    }
    *lista = aux;
}

// imprime produto
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

// imprime lista
void listar(no *lista)
{

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

// busca ocorrencias do item
no *buscarItem(no *lista, int cod)
{
    no *l2 = NULL;

    while (lista != NULL)
    {

        if (lista->dados.cod == cod)
        {
            no *aux;
            criar(&aux);

            aux->dados.cod = lista->dados.cod;
            aux->dados.data_validade = lista->dados.data_validade;
            strcpy(aux->dados.descricao, lista->dados.descricao);
            strcpy(aux->dados.marca, lista->dados.marca);
            aux->dados.quantidade = lista->dados.quantidade;
            aux->prox = l2;
            aux->ant = NULL;
            l2 = aux;
        }

        lista = lista->prox;
    }

    return l2;
}

//verica quandidade de produtos na lista
int contarItem(no *lista)
{
    if (lista == NULL)
    {
        return NULL;
    }
    else
    {
        int qtd = 0;

        while (lista != NULL)
        {
            qtd += lista->dados.quantidade;

            lista = lista->prox;
        }

        return qtd;
    }
}

// Consultar
void consultar(no *lista)
{
    int codigo, qtd = 0;

    printf("\n\ndigite o código do produto a ser consultado:\n>>");

    fscanf(stdin, "%d", &codigo);

    if (lista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        no *lista_item = buscarItem(lista, codigo);

        if (lista_item != NULL)
        {
            listar(lista_item);
            printf("\n\nQuantidade total do produto em estoque: %d\n", contarItem(lista_item));
        }
        else
        {
            printf("\nProduto não disponível no estoque!\n");
        }
    }
    return;
}

//acha o registro com menor validade
no *acharAntigo(no *lista, int codigo)
{
    no *aux = NULL;

    while (lista != NULL) //achar primeira ocorrencia do produto na lista
    {
        if (lista->dados.cod == codigo)
        {

            aux = lista;

            break;
        }

        lista = lista->prox;
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

    return aux;
}

//verifica se a quantidade solicitada está disponível
bool prodDisponivel(no *lista, int cod, int qtd)
{
    no *aux = buscarItem(lista, cod);

    int disp = contarItem(aux);

    return (disp - qtd) >= 0;
}

//remover nó da lista;
no *removerNo(no *lista, no *No)
{
    no *atual = lista;

    while (atual != NULL && atual != No)
    {

        atual = atual->prox;
    }

    if (atual == NULL)
    {

        return lista;
    }

    if (lista == atual)
    {
        lista = atual->prox;
    }
    else
    {
        atual->ant->prox = atual->prox;

    }

    if (atual->prox != NULL)
    {
        atual->prox->ant = atual->ant;
    }

    free(atual);
    return lista;
}

// Retirar produto
void removerProduto(no **lista)
{
    if ((*lista) == NULL)
    {
        printf("Lista vazia!!\n");
    }
    else
    {
        int codigo, qtd;

        printf("\n\ndigite o código do produto a ser retirado: \n>>");
        fscanf(stdin, "%d", &codigo);

        printf("digite a quantidade a ser retirada: \n>>");
        fscanf(stdin, "%d", &qtd);

        if (!prodDisponivel(*lista, codigo, qtd))
        {
            printf("Produto ou quantidade desejada indisponível no estoque!\n");

            return;
        }
        else
        {
            while (qtd > 0)
            {
                no *antigo = acharAntigo(*lista, codigo);

                int sobra = antigo->dados.quantidade - qtd;

                if (sobra > 0)
                {
                    antigo->dados.quantidade = sobra;
                    break;
                    return;
                }
                else if (sobra == 0)
                {
                    *lista = removerNo(*lista, antigo);
                    break;
                    return;
                }
                else
                {
                    *lista = removerNo(*lista, antigo);

                    qtd = sobra * -1;
                }
            }
        }
    }
}

int main()
{

    no *lista = NULL;

    int opcao = 0, item;

    while (opcao != 5)
    {
        printf("\n\n**************MENU*************\n\n");
        printf("1 - Listar\n");
        printf("2 - Inserir\n");
        printf("3 - Remover\n");
        printf("4 - Consultar\n");
        printf("5 - Sair\n>>");

        char pause;

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n****Listando estoque****\n\n");
            listar(lista);
            setbuf(stdin, NULL);
            /*printf("\nPress ENTER to continue...");
            scanf("%c", &pause);*/

            break;

        case 2:
            inserirProduto(&lista);
            setbuf(stdin, NULL);
            /*printf("\nPress ENTER to continue...");
            scanf("%c", &pause); */
            break;
        case 3:
            removerProduto(&lista);
            setbuf(stdin, NULL);
            /*printf("\nPress ENTER to continue...");
            scanf("%c", &pause);*/
            break;
        case 4:
            consultar(lista);
            setbuf(stdin, NULL);
            /*printf("\nPress ENTER to continue...");
            scanf("%c", &pause);*/

        case 5:

            break;

        default:
            printf("Opcao invalida. Tente de novo.\n");

            continue;
        }
        //system("clear");
    }

    return 0;
};
