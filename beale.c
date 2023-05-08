/*
 * Cifras Beale
 * Autor:
 *   Mateus Siqueira Ruzene - GRR:20221223
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include "libchaves.h"
#include "liblista.h"
#include "libcifra.h"
#include "libcodifica.h"
#include "libdecodifica.h"

#define CODIFICA 1
#define DECODIFICA 2
#define LINESIZE 1024
#define TAM 50

struct argumentos
{
    int opcao;
    char *livro;
    char *entrada;
    char *saida;
    char *chaves;
};
typedef struct argumentos argumentos_t;

/* Cria e inicializa os argumentos do programa */
argumentos_t *cria_argumentos()
{
    argumentos_t *args;

    if (!(args = malloc(sizeof(argumentos_t))))
    {
        perror("Erro ao alocar argumentos.");
        return NULL;
    }
    args->opcao = 0;
    args->livro = NULL;
    args->entrada = NULL;
    args->saida = NULL;
    args->chaves = NULL;

    return args;
}
/* Trata os argumentos passados pelo usuário e adiciona na struct argumentos */
argumentos_t *trata_argumentos(int argc, char **argv)
{
    int option;

    argumentos_t *arg = cria_argumentos();

    while ((option = getopt(argc, argv, "edb:m:o:c:i:")) != -1)
    {
        switch (option)
        {
        case 'e':
            arg->opcao = CODIFICA;
            break;
        case 'd':
            arg->opcao = DECODIFICA;
            break;
        case 'b':
            arg->livro = optarg;
            break;
        case 'm':
            arg->entrada = optarg;
            break;
        case 'o':
            arg->saida = optarg;
            break;
        case 'c':
            arg->chaves = optarg;
            break;
        case 'i':
            arg->entrada = optarg;
            break;
        default:
            return NULL;
            break;
        }
    }

    return arg;
}

int main(int argc, char **argv)
{
    FILE *entrada, *saida, *livro, *cifra;
    argumentos_t *argumentos;

    srand(time(NULL));

    if (argc == 1)
    {
        printf("Nenhum argumento fornecido.\n");
        return 0;
    }

    argumentos = trata_argumentos(argc, argv);
    entrada = fopen(argumentos->entrada, "r");
    saida = fopen(argumentos->saida, "w");

    if (argumentos->opcao == CODIFICA)
    {
        livro = fopen(argumentos->livro, "r");
        cifra = fopen(argumentos->chaves, "w");

        codifica_com_livro(entrada, saida, livro, cifra);

        fclose(cifra);
        fclose(livro);
    }
    else
    {
        if (argumentos->livro)
        {
            livro = fopen(argumentos->livro, "r");
            decodifica_com_livro(livro, entrada, saida);
            fclose(livro);
        }
        else
        {
            cifra = fopen(argumentos->chaves, "r");
            decodifica_com_arq_chaves(entrada, saida, cifra);
            fclose(cifra);
        }
    }

    free(argumentos);
    fclose(entrada);
    fclose(saida);

    return 0;
}