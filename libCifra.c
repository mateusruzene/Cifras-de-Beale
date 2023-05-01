/*
 * Lib Cifra
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCifra.h"
#include "libChaves.h"
#include "libLista.h"

int aleat_num_cifra(chaves_t *chaves, char letra)
{
  nodo_chaves_t *chave = busca_chave(chaves, letra);
  nodo_lista_t *aux;
  int aleatorio = rand() % chave->numeros->tam - 1;

  aux = chave->numeros->primeiro;
  for (int i = 0; i < aleatorio; i++)
    aux = aux->prox;

  return aux->num;
}

int letra_prox_palavra(FILE *texto, char *letra)
{
  char aux[64];
  int status = fscanf(texto, "%ls", aux);
  if (status == -1)
    return 0;
  *letra = aux[0];

  return 1;
}

void adiciona_letra_cifra(chaves_t *chaves, char letra, int numPosition)
{
  nodo_chaves_t *aux;

  if (!verifica_chave_existente(chaves, letra))
  {
    aux = adiciona_ordem_chaves(chaves, letra);
    adiciona_inicio_lista(aux->numeros, numPosition);
    return;
  }

  aux = busca_chave(chaves, letra);
  adiciona_inicio_lista(aux->numeros, numPosition);

  return;
}

chaves_t *cria_chaves_livro(FILE *livroCifras)
{
  char letra;
  int i;

  chaves_t *chaves = cria_chaves();
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

void montaLinhaCifra(FILE *cifras, chaves_t *chaves, char letra)
{
  char *linha, *linhaFormatada;
  int numPosicao;
  nodo_chaves_t *aux = adiciona_ordem_chaves(chaves, letra);

  linha = leLinha(cifras);
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

chaves_t *cria_chaves_arq_cifra(FILE *cifras)
{
  char letra;
  int status = 0;

  chaves_t *chaves = cria_chaves();
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

void escreve_arq_chaves(chaves_t *chaves, FILE *arq)
{
  nodo_chaves_t *auxChaves;
  nodo_lista_t *auxLista;

  auxChaves = chaves->primeiro;
  auxLista = chaves->primeiro->numeros;
  while (auxChaves)
  {
    fprintf(arq, "%c: ", auxChaves->letra);
    while (auxLista)
    {
      fprintf(arq, "%d ", auxLista->num);
      auxLista = auxLista->prox;
    }
    fseek(arq, -sizeof(char), SEEK_CUR);
    fprintf(arq, "\n");
    auxChaves = auxChaves->prox;
    auxLista = auxChaves->numeros;
  }
}