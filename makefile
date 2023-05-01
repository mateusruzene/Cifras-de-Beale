# Makefile de exemplo (Manual do GNU Make)
CC=gcc
CFLAGS= -Wall -std=c99

OBJS= beale.o libChaves.o libLista.o libCifra.o libCodifica.o libDecodifica.o

all: beale

beale: $(OBJS)
	$(CC) -o beale $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -f $(OBJS)

purge:
	rm -f $(OBJS) beale