#include <stdio.h>
#include <stdlib.h>
#define CHAO 0
#define PAREDE 1
#define VOCE 2
#define GRAMA 3
#define SAIDA 4
//Uso do teclado na tabela ASC2
#define ACIMA 119
#define ABAIXO 115
#define DIREITA 100
#define ESQUERDA 97
#define Q 113
#define OK 1
#define ERRO 2

int coluna_atual = 1,
linha_atual = 1,
coluna_atual2 = 1,
linha_atual2 = 1;

int key,passos;


/* O Mapa */
int mapa[10][20] = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
//Função para criar o mapa;
void gera_mapa(  )
{
    int m, n;

    for (m = 0; m < 10;m++)
    {
        for (n = 0;n<20;n++)
        {
            if (mapa[m][n] == 0)
            {
                mapa[m][n] = rand() % 4; 

                if (mapa[m][n] == 2)
                {
                    mapa[m][n] = 0;
                }
            }
        }
    }
    mapa[9][18] = 4;//Posição de saída do mapa
}
//função que desenha o mapa natela;
int desenhar_mapa()
{
    int linha,coluna;

    for (linha=0;linha<10;linha++) {
        for (coluna=0;coluna<20;coluna++) {
//coloca o perçonagem no labirinto na posição de inicio
            if ((linha == linha_atual) && (coluna == coluna_atual)) {
                printf("&");
                continue;
            }
            if (mapa[linha][coluna] == CHAO)
                printf(" ");
            if (mapa[linha][coluna] == PAREDE)
                printf("|");
            if (mapa[linha][coluna] == GRAMA)
                printf("*");
            if (mapa[linha][coluna] == SAIDA)
                printf("#");

        }
        printf("\n");
    }
    return OK;
}


int main(){

    do {
//chama as funções para gerar o mapa na tela;
        gera_mapa();
        desenhar_mapa();

        do {
//Move o perssonagem pelo caminho;
//A cada movimento ele apaga o mapa e redesenha;
            key=getch();

            if (key==ACIMA){

                linha_atual -= 1;
                passos += 1;

                if (mapa[linha_atual][coluna_atual] == PAREDE){
                    linha_atual +=1;
                }

                system("clear");
                desenhar_mapa();
            }

            if (key==ABAIXO){

                linha_atual += 1;
                passos += 1;

                if ((mapa[linha_atual][coluna_atual] == PAREDE)){
                    linha_atual -= 1;
                }

                system("clear");
                desenhar_mapa();
            }

            if (key==DIREITA){

                coluna_atual += 1;
                passos += 1;

                if ((mapa[linha_atual][coluna_atual] == PAREDE)){
                    coluna_atual -= 1;
                }

                system("clear");
                desenhar_mapa();
            }

            if (key==ESQUERDA){

                coluna_atual -= 1;
                passos += 1;

                if ((mapa[linha_atual][coluna_atual] == PAREDE)){
                    coluna_atual += 1;
                }

                system("clear");
                desenhar_mapa();
                printf("@");
            }
//condição de saida;
            if (key==Q){

                printf("\n\n\nPressione Qualquer Para Sair . .\n");
                getch();
                exit(2);

            }

        } while(mapa[linha_atual][coluna_atual]!=SAIDA);

        coluna_atual =1;
        linha_atual=1;
//Quando o personagem chega ao fim da concluido;
        printf("\n\n Concluido\n");
        getch();
        passos = 0;
        system("clear");

    } while(key!=Q);

    exit(2);
}