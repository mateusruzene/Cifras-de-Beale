/*
 * TAD LISTA
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "liblista.h"

struct lista_t *cria_lista()
{
    struct lista_t *lista;
    if (!(lista = malloc(sizeof(struct lista_t))))
        return NULL;

    lista->primeiro = NULL;
    lista->tam = 0;

    return lista;
}

struct lista_t *destroi_lista(struct lista_t *l)
{
    struct nodo_lista_t *aux;

    if (l->primeiro == NULL)
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

int adiciona_inicio_lista(struct lista_t *l, int novo_valor)
{
    struct nodo_lista_t *novo;

    if (!(novo = malloc(sizeof(struct nodo_lista_t))))
        return 0;

    novo->num = novo_valor;
    novo->prox = l->primeiro;
    l->primeiro = novo;
    l->tam++;

    return 1;
}

int verifica_num_existente(struct lista_t *lista, int valor)
{
    struct nodo_lista_t *aux;

    aux = lista->primeiro;
    while (aux)
    {
        if (valor == aux->num)
            return 1;
        aux = aux->prox;
    }

    return 0;
}