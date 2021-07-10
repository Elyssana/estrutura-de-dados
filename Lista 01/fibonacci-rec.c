// 1) Faça um programa que exibe na tela os elementos de uma série de fibonacci de forma imperativa e recursiva, depois calcule a complexidade de cada algoritmo.

#include <stdio.h>
int cont = 0;
int Fibonacci(int n)
{
    if (n <= 2) 
    {
        return 1;//(1)
    }
    else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
        //printf("(%d)", cont++);
        //return result;
    }
}//(2^n)+1

void loop(int n)
{
    if (n == 0) //(1)
    {
        return;
    }

    else
    {
        loop(n - 1); //(n)

        printf(" %d ", Fibonacci(n)); //(2^n)
    }
}//(n)*(2^n)

int main()
{

    int n;

    printf("Digite um numero: ");

    scanf("%d", &n);

    loop(n);
}//O((2^n)*(n))