#include <stdio.h>
struct nodo_lista
{
    int num;
    struct nodo_lista *prox;
};
typedef struct nodo_lista nodo_lista_t;

struct lista
{
    int tam;
    nodo_lista_t *primeiro;
};
typedef struct lista lista_t;

/*
 * Cria uma Lista vazia
 */
lista_t *cria_lista();

/*
 * Destroi a Lista e retorna NULL.
 */
lista_t *destroi_lista(lista_t *l);

/*
 * Adiciona um nodo novo na primeira posicao da lista.
 * Retorna 1 em caso de sucesso, 0 caso contrario.
 */
int adiciona_inicio_lista(lista_t *l, int novo_valor);

/* Verifica se existe o número dentro da lista, retorna 1 se existir, caso contrário 0 */
int verifica_num_existente(lista_t *lista, int valor);