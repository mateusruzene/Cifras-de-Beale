#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define LINESIZE 1024
#define TAM 50


int main() {

    FILE *arq;
    size_t i = 0;
    char *stringArq;

    if(!(stringArq = malloc(1024))){
        perror("Erro ao criar string");
        exit(1);
    }


    arq = fopen("livroCifra.txt", "r");
    if (!arq) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    fread(stringArq, LINESIZE, LINESIZE, arq); 

    printf("%s", stringArq);
    printf("\n");
    printf("\n");


    while (stringArq[i] != '\0') {
        if(i == 0)
            printf("%c ", stringArq[i]);
        if(stringArq[i] == 32)
            printf("%c ", stringArq[i+1]);
        i++;
    }
    
    printf("\n");
    fclose(arq);


    return 0;
}
