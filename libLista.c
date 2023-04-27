/*
 * TAD LISTA
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libLista.h"

lista_t *cria_lista()
{
    lista_t *lista;
    if (!(lista = malloc(sizeof(lista_t))))
        return NULL;

    lista->primeiro = NULL;
    lista->tam = 0;

    return lista;
}


lista_t *destroi_lista(lista_t *l)
{
    nodo_lista_t *aux;

    if(l->primeiro == NULL)
        return NULL;

    while (l->primeiro != NULL)
    {
        aux = l->primeiro;
        l->primeiro = (l->primeiro)->prox;
        free(aux);
    }
    free(l);
    l = NULL;

    return l;
}


int adiciona_inicio_lista(lista_t *l, int novo_valor)
{
    nodo_lista_t *novo;

    if (!(novo = malloc(sizeof(nodo_lista_t))))
        return 0;

    novo->num = novo_valor;
    novo->prox = l->primeiro;
    l->primeiro = novo;
    l->tam ++;

    return 1;
}