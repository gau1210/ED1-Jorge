#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct pilha {
    int n;
    int dados[MAX];
} Pilha;

Pilha* cria() {

    Pilha *p = malloc(sizeof(Pilha));

    if (p != NULL) {
        p->n = 0;
    }

    return p;
}
void insere(Pilha *p, int valor) {
    p->dados[p->n] = valor;
    p->n++;
}
void exibe(Pilha *p) {
    for (int i = 0; i < p->n; i++)

        printf("%3d", p->dados[i]);
}

Pilha* inverte(Pilha *p) {

    Pilha *aux = cria();

    while (p->n > 0) {
        aux->dados[aux->n] = p->dados[p->n - 1];
        p->n--;
        aux->n++;
    }
    return aux;
}
int main() {

    Pilha *p = cria();

    insere(p, 32);
    insere(p, 45);
    insere(p, 78);

    exibe(p);

    p = inverte(p);
    printf("\n");
    exibe(p);
}
