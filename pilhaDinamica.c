#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "pilhaDinamica.h"
#include "fila.h"

typedef struct elemento {
    struct aluno dados;
    struct elemento *proximo;
} Elemento;

struct pilha {
    Elemento *topo;
};

Pilha * criarPilha()
{
    Pilha *pilha = malloc(sizeof(Pilha));

    if(pilha != NULL) {
        pilha->topo = NULL;
    }
    return pilha;
}


int vazia(Pilha *pilha)
{
    if(pilha == NULL || pilha->topo == NULL)
        return 1;
    return 0;
}

int cheia(Pilha *pilha)
{
    // ???????

    return 0;
}

int tamanho(Pilha *pilha)
{
    if(vazia(pilha))
        return 0;

    int cont = 0;
    Elemento *aux = pilha->topo;

    while(aux != NULL) {
        cont += 1;
        aux = aux->proximo;
    }
    return cont;
}


int inserirPilha(Pilha *pilha, struct aluno dados)
{
    if(pilha == NULL)
        return 0;

    Elemento *novo = malloc(sizeof(Elemento));
    if(novo == NULL)
        return 0;

    strcpy(novo->dados.nome, dados.nome);
    novo->dados.matricula = dados.matricula;

    if(pilha->topo == NULL)
        pilha->topo =  novo;

    else {
        novo->proximo = pilha->topo;
        pilha->topo = novo;
    }

    return 1;
}


int imprimePilha(Pilha *pilha)
{
    if(vazia(pilha))
        return 0;

    Elemento *aux = pilha->topo;
    while(aux != NULL) {
        printf("%s: %d\n", aux->dados.nome, aux->dados.matricula);
        aux = aux->proximo;
    }
    return 1;
}


struct aluno * acessar(Pilha *pilha)
{
    if(vazia(pilha))
        return NULL;

    return &(pilha->topo->dados);
}


struct aluno * remover_topo(Pilha *pilha)
{
    if(vazia(pilha))
        return NULL;

    Elemento *aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(aux);

    return &(aux->dados);
}


void destruir(Pilha *pilha)
{
    if(!vazia(pilha)) {
        Elemento *aux;
        while(pilha->topo != NULL) {
            aux = pilha->topo;
            pilha->topo = pilha->topo->proximo;
            free(aux);
        }
        pilha->topo = NULL;
    }
}
