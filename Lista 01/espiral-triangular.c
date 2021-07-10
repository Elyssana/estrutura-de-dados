// 2) Considere uma “espiral triangular” que parte da origem das coordenadas e passa
#include <stdio.h>


void Q1( int c[] , int i )//Quadrante 1
{
    if(i <= 0){
        return; 
    }

    else{

        Q1( c , i-1 );

        c[0] += 1;
        c[1] += 1;

        return;
    }

}

void Q4( int c[] , int i )//Quadrante 4
{
    if(i <= 1){
        c[0] = 1;
        return; 
    }

    else{

        Q4( c , i-1 );

        c[0] += 2;
        c[1] -= 1;

        return;
    }

}

void Q3( int c[] , int i )//Quadrante 3
{
    if(i <= 0){
        return; 
    }

    else{

        Q3( c , i-1 );

        c[0] -= 2;
        c[1] -= 1;

        return;
    }

}


int Espiral(int n, int n_final)
{
    
    int coord[] = {0,0}; //vetor armazena a coordenada X e Y respectivamente
    int i;

    if( n % 3 == 2) // coordenadas do ponto n pertence ao quadrante 1
    {

        i = (n/3)+1; // i = quantas vezes o quadrante se repete na espiral

        Q1(coord,i);
    }

    else if( n % 3 == 1) // coordenadas do ponto n pertence ao quadrante 4
    {
        i = (n/3)+1; // i = quantas vezes o quadrante se repete na espiral

        Q4(coord,i);
    }

    else if( n % 3 == 0) // coordenadas do ponto n pertence ao quadrante 3
    {
        i = (n/3); // i = quantas vezes o quadrante se repete na espiral

        Q3(coord,i);
    }

    if(n==n_final){

        printf("\nCoordenadas do ponto %d: %d,%d.\n\n", n, coord[0], coord[1]);
    }
}


int main ()
{
    int n;

    scanf("%d", &n);

    int i = 0;
    while(i <= n){
        
        Espiral(i,n); 
        i++;
    }

}