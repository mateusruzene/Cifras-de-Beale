/*
 * TAD CHAVES
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include "liblista.h"
struct nodo_chaves_t
{
    char letra;
    struct lista_t *numeros;
    struct nodo_chaves_t *prox;
};
struct chaves_t
{
    struct nodo_chaves_t *primeiro;
    int tam;
};

/*
 * Cria uma Lista vazia
 */
struct chaves_t *cria_chaves();

/*
 * Destroi a chaves e as listas de números e retorna NULL.
 */
struct chaves_t *destroi_chaves(struct chaves_t *l);

/*
 * Verifica se existe uma chave na lista de chaves.
 * Retorna 1 em caso de existir, 0 caso contrario.
 */
int verifica_chave_existente(struct chaves_t *c, char valor);

/* Busca e retorna no nodo da struct chaves */
struct nodo_chaves_t *busca_chave(struct chaves_t *c, char valor);

/*
 * Adiciona um nodo novo na primeira posicao da chaves.
 * Retorna 1 em caso de sucesso, 0 caso contrario.
 */
struct nodo_chaves_t *adiciona_ordem_chaves(struct chaves_t *c, char novo_valor);

/* Busca se existe o número em alguma das chaves existentes, caso contrário retorna NULL */
struct nodo_chaves_t *busca_numero_na_chave(struct chaves_t *chaves, int valor);