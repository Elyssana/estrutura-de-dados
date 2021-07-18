#include <stdio.h>
#include <string.h>

int criaPilha(){

    int topo = -1;

    return topo;
}
/* */

int is_empty(int topo)
{
    if(topo != -1)
    {
        return 0;
    }
    else
    {
        // printf("Pilha vazia!");
        return 1;
    }
}

int desempilha(char vetor[], int topo)
{
    if(topo != -1)
    {
        vetor[topo] ='\0';
        topo -= 1;
    }
   
    return (topo);
}

int empilha(char vetor[], int topo, char elem, int max)
{    
    if (topo == max)
    {
        printf("Pilha cheia!");
    }
    else
    {
        topo += 1;
        vetor[topo] = elem;
    }
    return topo;

}


int verificaParenteses(char vetor[], char pilha[], int max)
{
    int i, topo = criaPilha();
    // printf("max = %d\n", max);

    for(i = 0; i<=max; i++){
        // printf("i = %d  - ", i);

        if(vetor[i] == '('){
            topo = empilha(pilha, topo, vetor[i], max);
            // printf("%d = %c\n", topo, pilha[topo]);
        }
        else if(vetor[i] == ')'){
            topo = desempilha(pilha, topo);
            // printf("else %d = %c\n", topo, pilha[topo]);
        }
    }

    // printf("pilha = %s\n", pilha);
    // printf("topo = %d ", topo);

    return is_empty(topo);
} 

int main()
{


    char str[100];
    scanf("%s", str);

    int tam = strlen(str);
    char pilha[tam];

    verificaParenteses(str, pilha, tam-1) ?printf("TRUE\n") :printf("FALSE\n");

}