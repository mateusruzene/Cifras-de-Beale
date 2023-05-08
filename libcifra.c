/*
 * Lib Cifra
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>
#include "libchaves.h"
#include "liblista.h"
#include "libcifra.h"

int aleat_num_cifra(struct chaves_t *chaves, char letra)
{
  struct nodo_chaves_t *chave = busca_chave(chaves, letra);
  struct nodo_lista_t *aux;
  int aleatorio = rand() % chave->numeros->tam - 1;

  aux = chave->numeros->primeiro;
  for (int i = 0; i < aleatorio; i++)
    aux = aux->prox;

  return aux->num;
}

int letra_prox_palavra(FILE *texto, char *letra)
{
  char aux[64];
  int status = fscanf(texto, "%s", aux);
  if (status == -1)
    return 0;
  *letra = aux[0];

  return 1;
}

void adiciona_letra_cifra(struct chaves_t *chaves, char letra, int numPosition)
{
  struct nodo_chaves_t *aux;

  if (!(aux = busca_chave(chaves, letra)))
  {
    aux = adiciona_ordem_chaves(chaves, letra);
    adiciona_inicio_lista(aux->numeros, numPosition);
    return;
  }

  adiciona_inicio_lista(aux->numeros, numPosition);

  return;
}

struct chaves_t *cria_chaves_livro(FILE *livroCifras)
{
  char letra;
  int i;

  struct chaves_t *chaves = cria_chaves();
  if (chaves == NULL)
    return NULL;
  rewind(livroCifras);
  i = 0;
  while (letra_prox_palavra(livroCifras, &letra))
  {
    letra = towlower(letra);
    adiciona_letra_cifra(chaves, letra, i);
    i++;
  }

  return chaves;
}

char *pega_linha(FILE *arq)
{
  int tam = 0;
  char *linha;

  while (fgetc(arq) != '\n')
    tam++;

  fseek(arq, -tam, SEEK_CUR);
  linha = malloc(sizeof(char) * (tam + 1));
  linha = fgets(linha, tam + 1, arq);
  linha[strcspn(linha, "\n")] = '\0';

  return linha;
}

void montaLinhaCifra(FILE *cifras, struct chaves_t *chaves, char letra)
{
  char *linha, *linhaFormatada;
  int numPosicao;
  struct nodo_chaves_t *aux = adiciona_ordem_chaves(chaves, letra);

  linha = pega_linha(cifras);
  linhaFormatada = strtok(linha, " ");

  while (linhaFormatada)
  {
    sscanf(linhaFormatada, "%d", &numPosicao);
    adiciona_inicio_lista(aux->numeros, numPosicao);
    linhaFormatada = strtok(NULL, " ");
  }
  free(linha);

  return;
}

struct chaves_t *cria_chaves_arq_cifra(FILE *cifras)
{
  char letra;

  struct chaves_t *chaves = cria_chaves();
  if (chaves == NULL)
    return chaves;

  rewind(cifras);

  fscanf(cifras, "%1c", &letra);
  getc(cifras);
  while (!feof(cifras))
  {
    montaLinhaCifra(cifras, chaves, letra);
    fscanf(cifras, "%1c", &letra);
    getc(cifras);
  }

  return chaves;
}

void escreve_arq_chaves(struct chaves_t *chaves, FILE *arq)
{
  struct nodo_chaves_t *auxChaves;
  struct nodo_lista_t *auxLista;

  auxChaves = chaves->primeiro;
  while (auxChaves)
  {
    fprintf(arq, "%c: ", auxChaves->letra);
    auxLista = auxChaves->numeros->primeiro;
    while (auxLista)
    {
      fprintf(arq, "%d ", auxLista->num);
      auxLista = auxLista->prox;
    }
    fprintf(arq, "\n");
    auxChaves = auxChaves->prox;
  }
}