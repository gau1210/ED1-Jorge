# include <stdlib.h>
# include <stdio.h>

int main(void)
{

    int vet[10];
    int maior,i=0,pos=0;

    for (i = 0; i < 10; ++i)
        {
        printf(" valores[%d]: ",i);
        scanf("%d", &vet[i]);
    }

    maior = vet[0];

    for (i = 0; i < 10; ++i) {

        if (vet[i] > maior){

        maior = vet[i];
        pos=i;

        }

    }

    printf("\n\n Maior: %d\n Posicao:%d\n", maior,pos);

    getch();
    return 0;
}

