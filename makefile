# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -std=c99 -g  # flags de compilacao
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = beale.o libChaves.o libLista.o
     
beale: beale.o 
	$(CC) -o beale beale.o libChaves.o libLista.o $(LDFLAGS)


libChaves.o: libChaves.c
	$(CC) -c $(CFLAGS) libChaves.c

libLista.o: libLista.c
	$(CC) -c $(CFLAGS) libLista.c

beale.o: beale.c
	$(CC) -c $(CFLAGS) beale.c

clean:
	rm -f $(objects) beale

