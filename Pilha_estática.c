#include <stdio.h>
#include <stdlib.h>


void push(int valor);
int pop(void);
int size(void);
int stacktop(void);

//Variáveis Globais;
int pilha[20];
int pos=0;

void push(int valor)
{
//Empilha o elemento no ventor, mas não pergunta se há espeço;
	pilha[pos]=valor;
	pos++;

	return;
}

int pop()
{

//Retorna o elemento do top da pilha sem verificar o fim;
	return (pilha[--pos]);

}

int size()
{

	return pos; //retorna o topo da pilha;
}

int stacktop()
{
	//retorna o topo, sem desempilhar;
	return pilha[pos];
}

int main()
{
    printf("\nInserir dados\n");
    push(1);
    push(2);
    push(3);

    printf("\ntamanho da pilha %d",size());

    printf("\npega dados %d",pop());
    printf("\npega dados %d",pop());
    printf("\npega dados %d",pop());

    printf("\ntamanho da pilha %d",size());


    return 0;
}
