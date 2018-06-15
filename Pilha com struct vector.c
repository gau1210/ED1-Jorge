#include <stdio.h>
#include <stdlib.h>
#define tam 100

struct pilha
{

    int top;
    int valor;
    int iten[tam];
};

int empty(struct pilha *p)
{

    if (p->top==-1)
    {

        return 1;

        }else{

        return 0;
    }

}

void push(struct pilha *p,int valor)
{

    if(p->top == (tam-1))
    {

        printf("Estouro da pilha\n");

    }else{
//Empilha o elemento no ventor;
	p->iten[++(p->top)]=valor;
	return;

    }

}

int pop(struct pilha *p)
{

    if(empty(p))
    {
        printf("\nPilha vazia");
        exit(1);

    }else{

//Retorna o elemento do top da pilha sem verificar o fim;
	return (p->iten[p->top--]);

    }

}

int size(struct pilha *p)
{

	return p->top+1; //retorna o topo da pilha;
}

int stackpop(struct pilha *p)
{
	//retorna o topo, sem desempilhar;
	return p->iten[p->top];
}

int main(void)
{

    struct pilha x;
    x.top=-1;

    push(&x,1);
    push(&x,2);
    push(&x,3);

    printf("\ntamanho da pilha %d",size(&x));
    printf("\nElemento do topo da fila %d", stackpop(&x));

    printf("\npega dados %d",pop(&x));
    printf("\npega dados %d",pop(&x));
    printf("\npega dados %d",pop(&x));


    return 0;
}
