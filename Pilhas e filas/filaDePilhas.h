#include "pilhaDeNumerosInteiros.h"

typedef struct NoFila NoFila;
typedef struct FilaDePilhas FilaDePilhas;

FilaDePilhas* criaFila();
void enfileirarPilha(FilaDePilhas* fila, Pilha* p);
Pilha* desenfileirarPilha(FilaDePilhas* fila);
void primeiraPilha(FilaDePilhas* fila);
int tamanhoFila(FilaDePilhas* fila);
int filaVazia(FilaDePilhas* fila);

void menuFilaDePilhas();
