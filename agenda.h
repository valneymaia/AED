#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

struct contato{
    char nome[50];
    long int telefone;
};

typedef struct elemento *Lista;

/*
retorna um ponteiro para uma lista caso haja
sucesso e NULL caso contrario
*/
Lista* criar();

void destruir(Lista *);

/*
retorna 1 caso o contato seja inserido
com sucesso na lista e 0 caso contrario
*/
int insereContato(Lista*, struct contato*);

/*
retorna 1 caso o contato seja encontrado na lista
e 0 caso contrario
*/
int buscaContato(Lista*, char nome[50], struct contato*);
/*
retorna 1 caso o contato seja encontrado na lista
e 0 caso contrario
*/

//funções extras
int removeContato(Lista*, char nome[50]);

int vazia(Lista *);

void imprime(Lista*cell);

#endif  AGENDA_H_INCLUDED
