typedef struct nodo_chaves_t
{
    char letra;
    lista_t *numeros;
    nodo_chaves_t *prox;
} nodo_chaves_t;

typedef struct chaves
{
    nodo_chaves_t *primeiro;
    int tam;
} chaves_t;

/*
 * Cria uma Lista vazia
 */
chaves_t *cria_chaves();

/*
 * Destroi a chaves e retorna NULL.
 */
chaves_t *destroi_chaves(chaves_t *l);

/*
 * Verifica se existe uma chave na lista de chaves.
 * Retorna 1 em caso de existir, 0 caso contrario.
 */
int verifica_chave_existente(chaves_t *l, char novo_valor);

/*
 * Adiciona um nodo novo na primeira posicao da chaves.
 * Retorna 1 em caso de sucesso, 0 caso contrario.
 */
int adiciona_ordem_chaves(chaves_t *l, char novo_valor);