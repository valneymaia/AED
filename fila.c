#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"
#include "fila.h"


struct fila {
    Pilha *p1;
    Pilha *p2;
};


Fila * criarFila()
{
    Fila *fila = malloc(sizeof(Fila));

    if(fila != NULL) {
        Pilha *p1 = criarPilha();
        Pilha *p2 = criarPilha();

        fila->p1 = p1;
        fila->p2 = p2;
    }

    return fila;
}

void inserirFila(Fila *fila, struct aluno dados)
{
    inserirPilha(fila->p1, dados);
}


void imprimeFila(Fila *fila)
{
    if(vazia(fila->p1)) {
        printf("Pilha 1 vazia\n");
    }
    else
        imprimePilha(fila->p1);
    if(vazia(fila->p2))
        printf("Pilha 2 vazia\n");
    else
        imprimePilha(fila->p2);
    printf("\n");
}


struct aluno *  topo(Fila *fila)
{
    if(vazia(fila->p1))
        return NULL;

    return acessar(fila->p1);
}


struct aluno * pop(Fila *fila)
{
    if(vazia(fila->p1))
        return NULL;

    return remover_topo(fila->p1);
}


void destruirFila(Fila *fila)
{
    if(!vazia(fila->p1))
        destruir(fila->p1);
    if(!vazia(fila->p2))
        destruir(fila->p2);
}
