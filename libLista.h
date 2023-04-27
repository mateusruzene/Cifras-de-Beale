typedef struct nodo_lista_t
{
    int num;
    nodo_lista_t *prox;
} nodo_lista_t;

typedef struct lista
{
    nodo_lista_t *primeiro;
    int tam;
} lista_t;


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