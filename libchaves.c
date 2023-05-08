/*
 * TAD CHAVES
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "liblista.h"
#include "libchaves.h"

struct chaves_t *cria_chaves()
{
    struct chaves_t *lista;
    if (!(lista = malloc(sizeof(struct chaves_t))))
        return NULL;

    lista->primeiro = NULL;

    return lista;
}

struct chaves_t *destroi_chaves(struct chaves_t *chaves)
{
    struct nodo_chaves_t *aux;

    if (chaves->primeiro == NULL)
        return NULL;

    while (chaves->primeiro != NULL)
    {
        aux = chaves->primeiro;
        chaves->primeiro = (chaves->primeiro)->prox;
        aux->numeros = destroi_lista(aux->numeros);
        free(aux);
    }
    free(chaves);
    chaves = NULL;

    return chaves;
}

int verifica_chave_existente(struct chaves_t *chaves, char valor)
{
    struct nodo_chaves_t *aux;

    if (chaves->primeiro == NULL)
        return 0;

    aux = chaves->primeiro;
    while (aux)
    {
        if (valor == aux->letra)
            return 1;
        aux = aux->prox;
    }

    return 0;
}

struct nodo_chaves_t *busca_chave(struct chaves_t *chaves, char valor)
{
    struct nodo_chaves_t *aux;

    if (!(verifica_chave_existente(chaves, valor)))
        return NULL;

    aux = chaves->primeiro;
    while (aux)
    {
        if (valor == aux->letra)
            return aux;
        aux = aux->prox;
    }
    return aux;
}

struct nodo_chaves_t *busca_numero_na_chave(struct chaves_t *chaves, int valor)
{
    struct nodo_chaves_t *aux;

    aux = chaves->primeiro;
    while (aux)
    {
        if (verifica_num_existente(aux->numeros, valor))
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

struct nodo_chaves_t *adiciona_ordem_chaves(struct chaves_t *chaves, char novo_valor)
{
    struct nodo_chaves_t *novo, *aux;

    if (!(novo = malloc(sizeof(struct nodo_chaves_t))))
        return NULL;

    if (!(chaves->primeiro))
    {
        chaves->primeiro = novo;
        novo->letra = novo_valor;
        novo->prox = NULL;
        novo->numeros = cria_lista();
        chaves->tam++;
        return novo;
    }

    aux = chaves->primeiro;
    while (aux->prox && novo_valor < aux->letra)
    {
        aux = aux->prox;
    }
    novo->letra = novo_valor;
    novo->prox = aux->prox;
    novo->numeros = cria_lista();
    aux->prox = novo;
    chaves->tam++;

    return novo;
}