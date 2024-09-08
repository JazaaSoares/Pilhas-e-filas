#include <stdio.h>
#include <stdlib.h>

typedef struct No No;
typedef struct Pilha Pilha;

Pilha* criaPilha();
void empilhar(Pilha* p, int valor);
int desempilhar(Pilha* p);
int topo(Pilha* p);
int tamanhoPilha(Pilha* p);
int pilhaVazia(Pilha* p);
void menuPilha();
