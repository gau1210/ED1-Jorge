#include <stdio.h>
#include <stdlib.h>

#define tam 100

struct  fila
{

	int itens[tam];
	int frent,fim;

};

//struct fila q;
//q.frent=q.fim=-1

int vazia(struct fila *pq)
{
	if(pq->frent == pq->fim)
	{
		return 1;
	}

	    return 0;

}

void inserefila(struct fila *pq,int x)
{
	/* Inversão das posições dos ponteiros. Se o sinal do vetor já foi
alcançado, então retorna-se ao início do vetor */

	if(pq->frent==tam-1)
	{

		pq->frent=0;


	}
	else
	{

		pq->fim++;

	}
	if(pq->fim==pq->frent)
	{
		printf("Estouro da fila\n");
		exit(1);
	}

	pq->itens[pq->frent]=x;
	return;
}

int tamanho(struct fila *pq)
{
	/* se o final da fila ainda não alcançou o final do vetor... */
	if(pq->frent<=pq->fim)
	{

		return pq->fim - pq->frent;/* ... então o tamanho da fila é o final
da fila menos o início da fila... */
	}

	/* ... se não, quer dizer que o ponteiro de final da fila já alcançou o final do vetor
e foi reposicionado para o início do vetor, então o tamanho da fila é a quantidade
de itens que ainda restam até chegar ao final do vetor somando itens que estão
no início do vetor */

	return pq->fim+pq->frent;
}

int frente(struct fila *pq)
{

	return pq->itens[pq->frent+1];

}
int retirafila(struct fila *pq)
{

	int x, i;
	if(vazia(pq))
	{
		printf("Fila vazia\n");
		exit(1);
	}

	/* Inversão das posições dos ponteiros. Se o inal do vetor já foi alcançado,
então retorna-se ao início do vetor */
	if (pq->frent==tam-1)
	{
		pq->frent=0;
	}
	else
	{

		pq->frent++;
	}
	return(pq->itens[pq->frent]);
}

int main(void)
{
	struct fila q;
	q.frent=-1;
	q.fim=-1;

	inserefila(&q, 1);
    inserefila(&q, 2);
    inserefila(&q, 3);
    inserefila(&q, 4);

printf("\nTamanho da fila %d", tamanho(&q));
printf("\nProximo da fila %d", frente(&q));
printf("\nTirando da fila %d", retirafila(&q));
printf("\nTirando da fila %d", retirafila(&q));
printf("\nTirando da fila %d", retirafila(&q));
printf("\nProximo da fila %d", frente(&q));
printf("\nTirando da fila %d", retirafila(&q));
printf("\nTamanho da fila %d", tamanho(&q));

printf("\nFila vazia %d", vazia(&q));

printf("\n");

return 0;

}