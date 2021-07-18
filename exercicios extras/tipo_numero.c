/*faça um programa que recebe um número no formato de string e informa o tipo do número fornecido (natural, inteiros ou real). Existe a possibilidade dos números fornecidos não ser válido para nenhum desses tipos, caso em que uma mensagem de erro deve ser exibida para o usuário*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool temSinal(char s[]) //verifica se o numero tem sinal
{
    if (s[0] == '+' || s[0] == '-')
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool NumeroValido(char s[])
{
    if (temSinal(s) && s[1] == '\0')// se houver apenas o sinal
    {
        return false;
    }

}

bool contemDigito(char string[], char c, int i)
{

    if (string[i] == '\0')
    { //se  for o fim da string

        return false;
    }
    else
    { //
        if (string[i] != c)
        { //se o caracter na posição atual não for o buscado ...

            contemDigito(string, c, ++i); //...passa-se à próxima posição;
        }
        else
        { //se o caracter é encontrado a função retorna true
            return true;
        }
    }
}



int main()
{
    
}