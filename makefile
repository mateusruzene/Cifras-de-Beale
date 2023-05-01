# Makefile de exemplo (Manual do GNU Make)
CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lm

CC=gcc

OBJS= beale.o libchaves.o liblista.o libcifra.o libcodifica.o libdecodifica.o

all: beale

beale: $(OBJS)
	$(CC) -o beale $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -f $(OBJS)

purge:
	rm -f $(OBJS) beale