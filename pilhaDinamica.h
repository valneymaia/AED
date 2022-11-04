#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

struct aluno {
    char nome[50];
    int matricula;
};

typedef struct pilha Pilha;

Pilha * criarPilha();
int vazia(Pilha *pilha);
int tamanho(Pilha *pilha);
int inserirPilha(Pilha *pilha, struct aluno dados);
int imprimePilha(Pilha *pilha);
int cheia(Pilha *pilha);
struct aluno * acessar(Pilha *pllha);
struct aluno * remover_topo(Pilha *pilha);
void destruir(Pilha *pilha);


#endif // PILHADINAMICA_H_INCLUDED
