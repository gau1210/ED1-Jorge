# include <stdio.h>
# include <stdlib.h>
# define max 3

 int vector[max];
 int top =0;
 int opcao;
 int tempo;

 void mostra(void){

 	for(tempo=top-1;tempo>=0;tempo--){


 		printf("%d%d\n",tempo,vector[tempo]);

 	}
 	system("pause");

 }

void insere(void){

    if(top==max){

	printf("\n A pilha esta cheia");

    }else{

	printf("\n Insira um valor");
	scanf("%d",&vector[top]);

	top++;
    }

}

void retira(void){

	if(top==0){

		printf("\n A pilha esta vazia");

	}else{

		top--;
	}

}

int menu(void){

    scanf("%d",&opcao);

    switch(opcao){

    	case 1 :insere();

    	break;

        case 2 :retira();

        break;

        case 3 :mostra();

        break;
    }
    return 0;

}

int main(int argc, char const *argv[]){

	while(opcao!=4){

		menu();

	}

	return 0;
}
