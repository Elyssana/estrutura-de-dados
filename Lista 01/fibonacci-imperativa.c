// 1) Faça um programa que exibe na tela os elementos de uma série de fibonacci de forma imperativa e recursiva, depois calcule a complexidade de cada algoritmo.
#include <stdio.h>

int Fibonacci(int n)
{


    if(n <= 2)
    {
        return 1;
    }
    else
    {
        int ult=1, penul=1, cont, atual=0;

        for (cont = 2; cont < n; cont++){

            atual = ult + penul;
            penul = ult;
            ult = atual;
            // printf("\n atual  =%d\n", atual);
            
        }

        return atual;
    }
        
}


int main(){

    int n;

    printf("Digite um numero: ");

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        
        printf("%d ", Fibonacci(i));

        
    }
    
}