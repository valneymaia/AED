#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "pilhaDinamica.h"

typedef struct fila Fila;

Fila * criarFila();
void imprimeFila(Fila *fila);
void inserirFila(Fila *fila, struct aluno dados);
struct aluno * pop(Fila *fila);
struct aluno *  topo(Fila *fila);

#endif // FILA_H_INCLUDED
