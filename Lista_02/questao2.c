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
    if (fila_vazia(fila))
    {
        printf("Pilha vazia!");

        return -1;
    }
    else
    {
        int item = fila->itens[fila->prim];

        //printf("\item removido: %d\n", item);

        for (int i = 0; i < fila->ult; i++)
        {
            fila->itens[i] = fila->itens[i + 1];
        }
        --fila->tam_atual;

        --fila->ult;

        return item;
    }
}

void imprime_fila(fila *fila)
{
    for (int i = 0; i < fila->tam_atual; i++)
    {
        printf("%d ", fila->itens[i]);
    }
}

int menu()
{
    int opcao = 0;

    while (opcao != 4)
    {
        printf("\n***************MENU***************\n");
        printf("\n - Opcao 1 - Inserir na fila ");
        printf("\n - Opcao 2 - Chamar próximo da fila");
        printf("\n - Opcao 3 - Imprimir fila");
        printf("\n - Opcao 4 - Sair do programa");
        printf("\n\nEscolha uma opção: \n>>");

        scanf("%d", &opcao);

        return opcao;
    }
}

int prioridade_vazia(fila *priori[])
{
    return (fila_vazia(priori[0]) &
            fila_vazia(priori[1]) &
            fila_vazia(priori[2]) &
            fila_vazia(priori[3]));
}

int ordem_de_atendimento(fila *ordemAtend, fila *priori[])
{
    while (!prioridade_vazia(priori))
    {
        for (int i = 3; i >= 0; i--)
        {
            if (priori[i]->tam_atual > 0)
            {
                int aux = remove_da_fila(priori[i]);

                insere_na_fila(ordemAtend, aux);
            }
        }
    }
}

int menu_chamar_proximo(fila *ordemAtend, fila *priori[])
{
    if (ordemAtend->tam_atual <= 0)
    {
        ordem_de_atendimento(ordemAtend, priori);
    }
    int prox = remove_da_fila(ordemAtend);

    printf("Proximo: %d\n", prox);
}

void menu_inserir(fila *priori[], int senha)
{
    int p;

    printf("\nSenha nº: %d\n", senha);

    printf("\nSelecione uma prioridade: (0, 1, 2 ou 3)\n>>");

    scanf("%d", &p);

    if (p < 0 || p > 3)
    {
        printf("\nOpção inválida!");
        return;
    }

    insere_na_fila(priori[p], senha);

    return 1;
}

int menu_imprimir_fila(fila *priori[], fila *ordemAtend)
{
    if (ordemAtend->tam_atual <= 0)
    {
        ordem_de_atendimento(ordemAtend, priori);
    }

    printf("\nPróximos: \n");

    imprime_fila(ordemAtend);

    if (!prioridade_vazia(priori))
    {
        printf("\n\nAguardando avaliação:\n");
        for (int i = 0; i < 4; i++)
        {
            if (!fila_vazia(priori[i]))
            {
                printf("\nPrioridade (%d): ", i);

                imprime_fila(priori[i]);
            }
        }
    }

    printf("\n");
}

int main()
{

    fila *priori[4];
    fila *ordemAtend = cria_fila();

    priori[0] = cria_fila();
    priori[1] = cria_fila();
    priori[2] = cria_fila();
    priori[3] = cria_fila();

    int opcao = 0, senha = 0, cont = 0;

    while (opcao != 4)
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            ++senha;
            menu_inserir(priori, senha);
            ++cont;

            break;
        case 2:
            menu_chamar_proximo(ordemAtend, priori);
            ++cont;
            break;

        case 3:
            menu_imprimir_fila(priori, ordemAtend);
            break;

        case 4:
            continue;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }

        if (cont == 4)
        {
            ordem_de_atendimento(ordemAtend, priori);
            cont = 0;
        }
    }
}
