#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LISTA criar_lista() {
    return NULL;
}

LISTA insere_cabeca(LISTA L, void *valor) {
    NODO *head = malloc(sizeof(NODO));
    head->valor = valor;
    head->proximo = L;
    return head;
}

void *devolve_cabeca(LISTA L) {
    void *h = L->valor;
    return h;
}

LISTA devolve_proximo(LISTA L) {
    LISTA p = L->proximo;
    return p;
}

LISTA remove_cabeca(LISTA L) {
    LISTA c = L->proximo;
    free(L);
    return c;
}

int lista_esta_vazia(LISTA L) {
    return L == NULL;
}

