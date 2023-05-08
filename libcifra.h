/*
 * Lib Cifra
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
/* Retorna um numero aleatorio da lista da cifra com a chave igual a @letra.*/;
int aleat_num_cifra(struct chaves_t *chaves, char letra);

/* lê a próxima palavra do arquivo do livroCifra */
int letra_prox_palavra(FILE *texto, char *letra);

/* Adiciona a letra na cifra e suas posições */
void adiciona_letra_cifra(struct chaves_t *chaves, char letra, int numPosition);

/* Cria as chaves a partir do livroCifras e retorna as chaves*/
struct chaves_t *cria_chaves_livro(FILE *livroCifras);

/* Cria as chaves atravez do aquivoCifra e retorna as chaves*/
struct chaves_t *cria_chaves_arq_cifra(FILE *cifras);

/* Escreve as chaves no arquivo de cifras*/
void escreve_arq_chaves(struct chaves_t *chaves, FILE *arq);