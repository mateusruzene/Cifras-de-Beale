/*
 * Lib Codifica
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libChaves.h"
#include "libCifra.h"
#include "libCodifica.h"

void codifica(chaves_t *chaves, FILE *entrada, FILE *saida)
{
    char letra;

    letra = fgets(letra, 1, entrada);
    while (!feof(entrada))
    {
        letra = towlower(letra);
        if (letra == ' ')
            fprintf(saida, "-1 ");
        else if (letra == '\n')
            fprintf(saida, "-2\n");
        else
            fprintf(saida, "%d ", aleatNumCifra(chaves, letra));
        letra = fgets(letra, 1, entrada);
    }
}

int codifica_com_livro(FILE *entrada, FILE *saida, FILE *livro, FILE *arqChaves)
{
    chaves_t *chaves = cria_chaves_livro(livro);
    if (chaves == NULL)
        return 1;

    codifica(chaves, entrada, saida);
    escreve_arq_chaves(chaves, arqChaves);

    destroi_chaves(chaves);

    return 0;
}