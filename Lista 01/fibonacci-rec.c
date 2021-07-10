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
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
        
}

void loop( int n)
{
    if(n == 0)
    {
        return;
    }

    else
    {
        loop(n-1); 
        
        printf(" %d ", Fibonacci(n));
    }

}

int main(){

    int n;

    printf("Digite um numero: ");

    scanf("%d", &n); 

    loop(n); 
    
}