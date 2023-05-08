#ifndef LIBLISTA_H
#define LIBLISTA_H
struct nodo_lista_t
{
    int num;
    struct nodo_lista_t *prox;
};

struct lista_t
{
    int tam;
    struct nodo_lista_t *primeiro;
};

/*
 * Cria uma Lista vazia
 */
struct lista_t *cria_lista();

/*
 * Destroi a Lista e retorna NULL.
 */
struct lista_t *destroi_lista(struct lista_t *l);

/*
 * Adiciona um nodo novo na primeira posicao da lista.
 * Retorna 1 em caso de sucesso, 0 caso contrario.
 */
int adiciona_inicio_lista(struct lista_t *l, int novo_valor);

/* Verifica se existe o número dentro da lista, retorna 1 se existir, caso contrário 0 */
int verifica_num_existente(struct lista_t *lista, int valor);

#endif