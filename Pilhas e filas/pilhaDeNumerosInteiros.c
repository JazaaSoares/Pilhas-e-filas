#include <stdio.h>
#include <stdlib.h>
#include "pilhaDeNumerosInteiros.h"

struct No {
    int valor;
    struct No* proximo;
};

struct Pilha {
    No* topo;
    int tamanho;
};


// Inicializa a pilha
Pilha* criaPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

// Empilha um elemento
void empilhar(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
}

// Desempilha um elemento
int desempilhar(Pilha* p) {
    if (p->topo == NULL) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    No* temp = p->topo;  //guarda o valor do topo da pilha
    int valor = temp->valor; //armazena o valor pra saber quem foi removido
    p->topo = p->topo->proximo; //altera o topo da pilha e vira o elemento embaixo dele
    free(temp); // limpa a memoria do elemento removido
    p->tamanho--; //diminui o tamanho da pilha
    return valor; // retorna quem foi removido
}

// Retorna o topo da pilha sem removê-lo
int topo(Pilha* p) {
    if (p->topo == NULL) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->topo->valor;
}

// Retorna o tamanho da pilha
int tamanhoPilha(Pilha* p) {
    return p->tamanho;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->tamanho == 0;
}

void menuPilha(Pilha* p) {
    int opcao, valor;
    do {
        printf("\nMenu Pilha:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Mostrar topo da pilha\n");
        printf("4. Verificar se esta vazia\n");
        printf("5. Mostrar tamanho\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls || clear");

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                empilhar(p, valor);
                printf("Valor empilhado com sucesso!");
                system("pause");
                system("cls || clear");
                break;
            case 2:
                valor = desempilhar(p);
                if (valor != -1) printf("Valor desempilhado: %d\n", valor);
                system("pause");
                system("cls || clear");
                break;
            case 3:
                valor = topo(p);
                if (valor != -1) printf("Topo da pilha: %d\n", valor);
                system("pause");
                system("cls || clear");
                break;
            case 4:
                printf(pilhaVazia(p) ? "Pilha vazia\n" : "Pilha não está vazia\n");
                system("pause");
                system("cls || clear");
                break;
            case 5:
                printf("Tamanho da pilha: %d\n", tamanhoPilha(p));
                system("pause");
                system("cls || clear");
                break;
            case 6:
                printf("Saindo do menu da pilha...\n");
                system("pause");
                system("cls || clear");
                break;
            default:
                printf("Opção inválida!\n");
                system("pause");
                system("cls || clear");
        }
    } while (opcao != 6);
}
