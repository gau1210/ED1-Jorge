#include<stdio.h>
#include<conio.h>

int main (void )
{
  int matriz[2][3],i,j,maior,menor;
  int auxi,auxj;

  printf ("\nDigite valor para os elementos da matriz\n\n");

  for ( i=0; i<2; i++ )
    for ( j=0; j<3; j++ )
    {
       printf ("\nElemento[%d][%d] = ", i, j);
       scanf ("%d", &matriz[i][j]);
}

    menor=matriz[0][0];
    for ( i=0; i<2; i++ )
    {
    for ( j=0; j<3; j++ )
    {
      if(matriz[i][j]<menor)
      {
        menor=matriz[i][j];
        auxi=i;
        auxj=j;

        }
      }
    }

    maior=matriz[0][0];
    for ( i=0; i<2; i++ )
    {
    for ( j=0; j<3; j++ )
    {
      if(matriz[i][j]>maior)
      {
        maior=matriz[i][j];
        auxi=i;
        auxj=j;

        }
      }
    }
    printf("\nMatriz[%d][%d]\nMenor valor da linha e:=%d\nO maior valor da coluna e:=%d\n",auxi,auxj,menor,maior);


  getch();
  return(0);
}
