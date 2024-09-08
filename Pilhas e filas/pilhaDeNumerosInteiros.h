#include <stdio.h>
#include <stdlib.h>

typedef struct No No;

typedef struct Pilha Pilha;

// Inicializa a pilha
Pilha* criaPilha();

// Empilha um elemento
void empilhar(Pilha* p, int valor);

// Desempilha um elemento
int desempilhar(Pilha* p);

// Retorna o topo da pilha sem removê-lo
int topo(Pilha* p);

// Retorna o tamanho da pilha
int tamanhoPilha(Pilha* p);

// Verifica se a pilha está vazia
int pilhaVazia(Pilha* p);

void menuPilha();
