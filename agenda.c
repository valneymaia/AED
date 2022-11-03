#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "agenda.h"

struct elemento{
    struct contato dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;


Lista* criar(){
    Lista *ldse = NULL;
    ldse = (Lista*)malloc(sizeof(Lista));


    if(ldse != NULL){
        *ldse = NULL;
    }
    return ldse;
}


int insereContato(Lista *ldse, struct contato* novosdados){
    if(ldse == NULL){
        return 0;
    }

    struct elemento *aux = *ldse;
    while(aux != NULL){
        if(aux->dados.telefone == novosdados->telefone){
            printf("\nEsse telefone ja estar salvo, tente outro numero! \n");
            return 0;
        }
        aux=aux->prox;
    }
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->dados = *novosdados;
        novo->prox = *ldse;
        *ldse = novo;
        printf("\nseu numero foi salvo!\n");
        return 1;

}

//verifica se a lista esta vazia
int vazia(Lista *ldse) {
    if (ldse == NULL || *ldse == NULL) {
        return 1;
    }

    else {
        return 0;
    }
}

//destruir lista
void destruir(Lista *ldse) {
    if (ldse != NULL) {
        Elemento *aux;
    while (*ldse != NULL) {
        aux = *ldse;
        *ldse = (*ldse)->prox;
        free(aux);
        }
    }
}


int removeContato(Lista*ldse, char nome[50]){
    if(vazia(ldse)){
        printf("Lista vazia, nao foi possivel remover.\n\n");
        return 0;
    }

    else if(strcmp(nome,(*ldse)->dados.nome)==0){
        Elemento *aux = *ldse;
        *ldse = aux->prox;
        free(aux);
        printf("contato removido com sucesso\n");
        return 1;
    }

    Elemento *ant = *ldse;
    Elemento *aux = ant->prox;

    while (aux != NULL && (strcmp(aux->dados.nome , nome)==1 || strcmp(aux->dados.nome , nome)==-1)) {
        ant = aux;
        aux = aux->prox;
    }
    if(aux==NULL) {
        printf("contato nao existe\n");
        return 0;
    }

    ant->prox = aux->prox;
    free(aux);
    printf("contato removido com sucesso\n");
    return 1;

}


int buscaContato(Lista *ldse, char nome[50], struct contato*a) {
    if (vazia(ldse))
        return 0;

    else {
        Elemento *aux = *ldse;

        while (aux != NULL && (strcmp(aux->dados.nome , nome)==1 || strcmp(aux->dados.nome , nome)==-1)) {
            aux = aux->prox;
        }
        if (aux == NULL) {
            return 0;
        }

        *a = aux->dados;
        return 1;
    }
}


void imprime(Lista*ldse){
    if (vazia(ldse)){
        printf("\nLista telefonica vazia\n");
        return;
    }

    struct elemento *aux= *ldse;
    while(aux!=NULL){
        printf("____________________\n");
        printf("%s : %ld\n", aux->dados.nome,aux->dados.telefone);
        aux=aux->prox;
    }
}

void editarContato(Lista *ldse){
    char nome[50], op1;
    long int n;
    if(vazia(ldse))
       return 0;
    printf("digite o nome de quem voce quer editar: \n");
    gets(nome);

    Elemento *aux = *ldse;

    while (aux != NULL && (strcmp(aux->dados.nome , nome)==1 || strcmp(aux->dados.nome , nome)==-1)) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        return 0;
    }

    printf("digite 1- mudar nome ou 2- mudar telefone: \n");
    scanf("%c", &op1);
    while(getchar()!='\n');
    if(op1=='1'){
        printf("digite o novo nome: \n");
        gets(nome);
        strcpy(aux->dados.nome,nome);
    }else if(op1=='2'){
        printf("digite um novo telefone: \n");
        scanf("%ld", &n);
        while(getchar()!='\n');
        aux->dados.telefone=n;
    }else{
    printf("opcão invalida \n");
    }
    return 1;
}
