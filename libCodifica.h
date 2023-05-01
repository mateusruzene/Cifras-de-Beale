/*
 * Lib Codifica
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include "libChaves.h"

/* Codifica uma mensagem qualquer contida em um arquivo ASCII usando um livro cifra. */
void codifica(chaves_t *chaves, FILE *entrada, FILE *saida);

/* Cria a codificação com o livroCifras */
int codifica_com_livro(FILE *entrada, FILE *saida, FILE *livro, FILE *arqChaves);