/*
 * TAD CHAVES
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include "liblista.h"
struct nodo_chaves
{
    char letra;
    lista_t *numeros;
    struct nodo_chaves *prox;
};
typedef struct nodo_chaves nodo_chaves_t;
struct chaves
{
    nodo_chaves_t *primeiro;
    int tam;
};
typedef struct chaves chaves_t;

/*
 * Cria uma Lista vazia
 */
chaves_t *cria_chaves();

/*
 * Destroi a chaves e as listas de números e retorna NULL.
 */
chaves_t *destroi_chaves(chaves_t *l);

/*
 * Verifica se existe uma chave na lista de chaves.
 * Retorna 1 em caso de existir, 0 caso contrario.
 */
int verifica_chave_existente(chaves_t *c, char valor);

/* Busca e retorna no nodo da struct chaves */
nodo_chaves_t *busca_chave(chaves_t *c, char valor);

/*
 * Adiciona um nodo novo na primeira posicao da chaves.
 * Retorna 1 em caso de sucesso, 0 caso contrario.
 */
nodo_chaves_t *adiciona_ordem_chaves(chaves_t *c, char novo_valor);

/* Busca se existe o número em alguma das chaves existentes, caso contrário retorna NULL */
nodo_chaves_t *busca_numero_na_chave(chaves_t *chaves, int valor);