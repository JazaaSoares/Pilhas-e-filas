#include "filaDePilhas.h"


struct NoFila {
    Pilha* pilha;
    struct NoFila* proximo;
};

struct FilaDePilhas {
    NoFila* frente;
    NoFila* tras;
    int tamanho;
};

struct No {
    int valor;
    struct No* proximo;
};

struct Pilha {
    No* topo;
    int tamanho;
};

// Inicializa a fila de pilhas
FilaDePilhas* criaFila() {
    FilaDePilhas* fila = (FilaDePilhas*)malloc(sizeof(FilaDePilhas));
    fila->frente = NULL;
    fila->tras = NULL;
    fila->tamanho = 0;
    return fila;
}

// Enfileira uma nova pilha
void enfileirarPilha(FilaDePilhas* fila, Pilha* p) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->pilha = p; //atribui pilha a um elemento novo
    novo->proximo = NULL; // atribui proximo = a NULL pois n�o existe ninguem atras do n� novo
    if (fila->tras == NULL) { // verifica se a fila n�o tem elemnto
        fila->frente = novo; // se n�o tiver, o novo no � o primeiro da fila
    } else {
        fila->tras->proximo = novo; // se tiver, indica que o ultimo no da fila tem alguem atr�s dele
    }
    fila->tras = novo; //elemento que entrou na fila passa a ser o ultimo da fila
    fila->tamanho++; //incrementa o tamanho da fila
}

// Desenfileira a pilha da frente
Pilha* desenfileirarPilha(FilaDePilhas* fila) {
    if (fila->frente == NULL) { //verifica se a pilha est� vazia
        printf("Erro: Fila de pilhas vazia!\n");
        return NULL;
    }
    NoFila* temp = fila->frente; // cria um temporario pra apontar para o no da frente da fila
    Pilha* pilha = temp->pilha; // armazena o valor da pilha que vai ser liberada
    fila->frente = fila->frente->proximo; // a frente agora vai ser a frente do proximo
    if (fila->frente == NULL) {
        fila->tras = NULL; // se o da frente for nulo o de tras � nulo tbm
    }
    free(temp);
    fila->tamanho--;
    return pilha; // o que foi removido da fila
}

// Fun��o que imprime a primeira pilha sem remov�-la
void primeiraPilha(FilaDePilhas* fila) {
    if (fila == NULL) {
        printf("Erro: Fila de pilhas n�o inicializada!\n");
        return;
    }

    if (fila->frente == NULL) {
        printf("Erro: Fila de pilhas vazia!\n");
        return;
    }

    NoFila* noFila = fila->frente;
    if (noFila == NULL) {
        printf("Erro: Fila n�o inicializada!\n");
        return;
    }

    Pilha* pilha = noFila->pilha;
    if (pilha == NULL) {
        printf("Erro: Pilha n�o inicializada!\n");
        return;
    }

    No* atual = pilha->topo;  // Come�a do topo da pilha
    if (atual == NULL) {
        printf("Erro: Pilha vazia!\n");
        return;
    }

    printf("Elementos da primeira pilha:\n");
    while (atual != NULL) {
        printf("%d\n", atual->valor);  // Imprime o valor do n� atual
        atual = atual->proximo;        // Vai para o pr�ximo n�
    }
}

// Retorna o tamanho da fila
int tamanhoFila(FilaDePilhas* fila) {
    return fila->tamanho;
}

// Verifica se a fila est� vazia
int filaVazia(FilaDePilhas* fila) {
    return fila->tamanho == 0;
}

void menuFilaDePilhas(FilaDePilhas* f) {
    int opcao;
    Pilha* p;
    do {
        printf("\nMenu Fila de Pilhas:\n");
        printf("1. Enfileirar Pilha\n");
        printf("2. Desenfileirar Pilha\n");
        printf("3. Mostrar Primeira Pilha\n");
        printf("4. Verificar se a Fila est� Vazia\n");
        printf("5. Mostrar Tamanho da Fila\n");
        printf("6. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        system("cls || clear");

        switch (opcao) {
            case 1:
                p = criaPilha();
                menuPilha(p);
                enfileirarPilha(f, p);
                sleep(1);
                system("cls || clear");
                break;
            case 2:
                p = desenfileirarPilha(f);
                if (p != NULL) printf("Pilha desenfileirada!\n");
                system("pause");
                system("cls || clear");
                break;
            case 3:
                primeiraPilha(f);
                system("pause");
                system("cls || clear");
                break;
            case 4:
                printf(filaVazia(f) ? "Fila de pilhas vazia\n" : "Fila de pilhas n�o est� vazia\n");
                system("pause");
                system("cls || clear");
                break;
            case 5:
                printf("Tamanho da fila: %d\n", tamanhoFila(f));
                system("pause");
                system("cls || clear");
                break;
            case 6:
                printf("Saindo do menu da fila...\n");
                sleep(1);
                system("cls || clear");
                break;
            default:
                printf("Op��o inv�lida!\n");
                sleep(1);
                system("cls || clear");
        }
    } while (opcao != 6);
}
