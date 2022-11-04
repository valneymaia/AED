#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "pilhaDinamica.h"
#include "fila.h"

void menu(){
    printf("___________________________________\n");
    printf("1- Inserir aluno\n");
    printf("2- Remover aluno\n");
    printf("3- Acessar o aluno no topo da pilha\n");
    printf("4- Imprimir a pilha\n");
    printf("5- Destruir pilhas\n");
    printf("6- Sair do Programa\n");
    printf("___________________________________\n");
    printf("Sua opcao: ");
}


void escolha(Fila *fila)
{
    struct aluno *dados = malloc(sizeof(struct aluno));
    char op;
    char nome[50];

    for(;;)
    {
        menu();
        scanf("%c", &op);
        while( getchar() != '\n');
        printf("\n----------\n");

        switch(op)
        {
        case '1':
            printf("Nome: ");
            gets(nome);
            printf("Matricula: ");
            scanf("%d", &dados->matricula);
            while( getchar() != '\n');
            strcpy(dados->nome, nome);
            inserirFila(fila, *dados);
            break;

        case '2':
            pop(fila);
            break;

        case '3':
            dados = topo(fila);
            printf("_______________\n%s : %d\n_______________\n", dados->nome, dados->matricula);
            break;

        case '4':
            imprimeFila(fila);
            break;

        case '5':
            destruirFila(fila);
            //destruir(fila->p2);
            break;

        case '6':
            printf("Encerrando o programa...\n");
            //destruir(fila->p1);
            //destruir(fila->p2);
            return;

        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
}


int main()
{
    Fila *fila = criarFila();

    escolha(fila);

    return 0;
}

/*
struct aluno *dados = malloc(sizeof(struct aluno));
strcpy(dados->nome, "Seu pai");
    dados->matricula = 12345;
    inserirFila(fila, *dados);

    strcpy(dados->nome, "Sua mae");
    dados->matricula = 40028922;
    inserirFila(fila, *dados);

    strcpy(dados->nome, "Sua irma");
    dados->matricula = 666;
    inserirFila(fila, *dados);

    imprimeFila(fila);

    pop(fila);
    pop(fila);
    imprimeFila(fila);
*/
