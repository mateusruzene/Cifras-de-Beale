/*
 * TAD CHAVES
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libLista.h"
#include "libChaves.h"

chaves_t *cria_chaves()
{
    chaves_t *lista;
    if (!(lista = malloc(sizeof(chaves_t))))
        return NULL;

    lista->primeiro = NULL;

    return lista;
}


chaves_t *destroi_chaves(chaves_t *chaves)
{
    nodo_chaves_t *aux;

    if(chaves->primeiro == NULL)
        return NULL;

    while (chaves->primeiro != NULL)
    {
        aux = chaves->primeiro;
        chaves->primeiro = (chaves->primeiro)->prox;
        free(aux);
    }
    free(chaves);
    chaves = NULL;

    return chaves;
}

int verifica_chave_existente(chaves_t *chaves, char novo_valor)
{
    nodo_chaves_t *aux;

    aux = chaves->primeiro;
    while (aux)
    {
        if(novo_valor == aux->letra)
            return 1;
        aux = aux->prox;
    }

    return 0;
}

int adiciona_ordem_chaves(chaves_t *chaves, char novo_valor)
{
    nodo_chaves_t *novo, *aux;

    if (!(novo = malloc(sizeof(nodo_chaves_t))))
        return 0;

    aux = chaves->primeiro;
    while ((aux->prox) &&  novo_valor < aux->letra)
    {
        aux = aux->prox;
    }
    

    novo->letra = novo_valor;
    novo->prox = aux->prox;
    aux->prox = novo;
    chaves->tam ++;

    return 1;
}