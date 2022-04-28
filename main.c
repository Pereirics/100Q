#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//1.
int length (LInt l) {
    int cont = 0;
    while (l != NULL) {
        cont++;
        l = l->prox;
    }
    return cont;
}

//2.
void freeL (LInt l) {
    LInt temp = l;
    while (l != NULL) {
        l = l->prox;
        free(temp->valor);
        free(temp);
        temp = l;
    }
}

//3.
void imprimeL (LInt l) {
    while (l != NULL) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//4.
LInt reverseL (LInt l){
    LInt before = NULL;
    LInt start = l;
    LInt after;
    while(l != NULL){
        after = l->prox;
        l->prox = before;
        before = l;
        l = after;
    }
    start = before;
    return start;
}

//5.
void insertOrd (LInt* l, int x) {
    LInt nova = malloc(sizeof(struct lligada));
    assert(nova != NULL);
    nova->valor = x;
    while (*l != NULL && (*l)->valor < x) {
        l = &((*l)->prox);
    }
    nova->prox = *l;
    *l = nova;
}





















