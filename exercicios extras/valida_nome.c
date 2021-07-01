/*faça um programa que receba um nome válido

para efeitos de teste, os nomes válidos são formados só por letra não existe a possibilidade de um nome ter zero caracteres o campo não deve permitir que a string inicie com uma letra minúscula nem com espaço*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


char maiusculas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char minusculas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char LETRAS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a',
                 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

//verifica se o caractere c está contido na string
bool contemCaracatere(char string[], char c, int i)
{

    if (string[i] != '\0')
    { //se não for o fim da string

        if (string[i] != c)
        { //se o caracter na posição atual não for o buscado ...

            contemCaracatere(string, c, ++i); //...passa-se à próxima posição;
        }
        else
        { //se o caracter é encontrado a função retorna true
            return true;
        }
    }
    else
    { //se chegar ao fim da string a função retorna false

        return false;
    }
}

//verifica se a string informada eh formada apenas por letras
bool soLetras(char s[], int i)
{

    bool ehLetra = contemCaracatere(LETRAS, s[i], 0);
    //printf("cotem %c %d",s[i], contem);

    if (s[i] != '\0' && (ehLetra == true))
    { //Se não for fim da string e for uma letra

        soLetras(s, ++i);
    }

    else if (s[i] == '\0')
    { //se chegar ao fim da string

        return true;
    }

    else
    {

        return false;
    }
}

//verifica se possui ao menos um caracter
bool maisDeUm(char s[])
{

    return strlen(s) >= 1;
    //return contemCaracatere(LETRAS, s[0], 0);
}

//verifica se a primeiras do nome inicia com maiusculas e todas as outras são minusculas
bool primMaiusc(char s[], int i)
{

    //verifica se a primeira letra eh maiuscula
    if (i == 0)
    {
        if (contemCaracatere(maiusculas, s[i], 0))
        {
            // printf("%c eh maiuscula\n", s[i]);

            return primMaiusc(s, ++i);
        }
        else
        {
            // printf("%c nao é maiuscula\n", s[i]);

            return false;
        }
    }
    
    //verifica se chegou no fim da string
    else if (s[i] == '\0')
    { 
        return true;
    }

    //verifica se os outros caracteres são minusculos
    else
    { 
        if (contemCaracatere(minusculas, s[i], 0))
        {
            //printf(" %c eh minuscula \n", s[i]);

            return primMaiusc(s, ++i);
        }

        else
        {
            //printf("%c não é minuscula\n", s[i]);

            return false;
        }
    }
}

void validarNome()
{
    char nome[100];

    printf("Digite um nome: \n");

    setbuf(stdin, NULL);

    scanf("%[^\n]s ", nome);
            
    //printf("so possui letras? %d\n", soLetras(s, 0));
    //printf("tem um ou mais caracter? %d\n", maisDeUm(s));
    //printf("Apenas a primeira letra eh maiscula? %d\n", primMaiusc(s, 0));

   
    printf(".\n.\nO nome \"%s\" eh ",nome);
    if (soLetras(nome, 0) && maisDeUm(nome) && primMaiusc(nome, 0))
    {
        
        printf("válido\n");
    }

    else
    {
        printf("inválido!\n");
    }
    setbuf(stdin, NULL);
    printf("\nPress to continue...");
    getchar();
}

int main()
{
    int opcao = 0;

    while (opcao != 2)
    {
        system("clear");
        printf("\n*************MENU************* \n\n");
        printf("1-Validar nome\n");
        printf("2-Sair\n\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        system("clear");
        switch (opcao)
        {
        case 1:
            
            validarNome();
            
            break;
        
        case 2:

            break;
        
        
        default:
            printf("Opcao invalida. Tente de novo.\n");
            
            break;
        }

        


    }
    
}