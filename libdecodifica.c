/*
 * Lib Decodifica
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libchaves.h"
#include "libcifra.h"
#include "libdecodifica.h"

void decodifica(chaves_t *chaves, FILE *entrada, FILE *saida)
{
  nodo_chaves_t *chave;
  int num;

  while (fscanf(entrada, "%d", &num) != -1)
  {
    if (num == -1)
    {
      fputc(' ', saida);
    }
    else if (num == -2)
    {
      fputc('\n', saida);
    }
    else if (num == -3)
    {
      fputc('?', saida);
    }
    else
    {
      chave = busca_numero_na_chave(chaves, num);
      if (chave == NULL)
        fputc('?', saida);
      else
        fputc(chave->letra, saida);
    }
  }
}

int decodifica_com_livro(FILE *livroCifras, FILE *entrada, FILE *saida)
{
  chaves_t *chaves = cria_chaves_livro(livroCifras);
  if (chaves == NULL)
    return 1;

  decodifica(chaves, entrada, saida);

  destroi_chaves(chaves);

  return 0;
}

int decodifica_com_arq_chaves(FILE *cifras, FILE *entrada, FILE *saida)
{
  chaves_t *chaves = cria_chaves_arq_cifra(cifras);
  if (chaves == NULL)
    return 1;

  decodifica(chaves, entrada, saida);

  destroiCifras(chaves);

  return 0;
}