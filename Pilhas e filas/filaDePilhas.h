#include "pilhaDeNumerosInteiros.h"

typedef struct NoFila NoFila;

typedef struct FilaDePilhas FilaDePilhas;


// Inicializa a fila de pilhas
FilaDePilhas* criaFila();
// Enfileira uma nova pilha
void enfileirarPilha(FilaDePilhas* fila, Pilha* p);
// Desenfileira a pilha da frente
Pilha* desenfileirarPilha(FilaDePilhas* fila);
// Retorna a primeira pilha sem removê-la
void primeiraPilha(FilaDePilhas* fila);
// Retorna o tamanho da fila
int tamanhoFila(FilaDePilhas* fila);
// Verifica se a fila está vazia
int filaVazia(FilaDePilhas* fila);

void menuFilaDePilhas();
