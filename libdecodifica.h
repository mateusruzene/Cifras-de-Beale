/*
 * Lib Decodifica
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */

/* Decodifica a entrada com as chaves e escreve no arquivo de saida*/
void decodifica(struct chaves_t *chaves, FILE *entrada, FILE *saida);

/* Decodifica para a saida o texto de entrada com base no livro de cifras.*/
int decodifica_com_livro(FILE *livroCifras, FILE *entrada, FILE *saida);

/* Decodifica a entrada com base no arquivo de cifras e escreve no arquivo de saida*/
int decodifica_com_arq_chaves(FILE *cifras, FILE *entrada, FILE *saida);