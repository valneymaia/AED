#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"


void menu(){
    printf("_______________________________________\n");
    printf("SELECIONE UMA OPCAO \n");
    printf("  1 - Inserir contato. \n");
    printf("  2 - Remover contato pelo nome. \n");
    printf("  3 - editar contato. \n");
    printf("  4 - Buscar contato pelo nome. \n");
    printf("  5 - Imprimir lista de contato. \n");
    printf("  6 - Destruir lista. \n");
    printf("  7 - Fechar progama. \n");
    printf("_______________________________________\nSua opcao: ");
}


struct contato * preenche(Lista *ldse, struct contato *dados){
    char nome[50];
    long int numero;

    printf("Nome: ");
    gets(nome);

    printf("Telefone: ");
    scanf("%ld", &numero);
    while(getchar() != '\n');

    strcpy(dados->nome, nome);
    dados->telefone = numero;

    return dados;
}


void ler_opcao(Lista *ldse){
    char op, nomeNovo[50];
    struct contato *dados = (struct contato*)malloc(sizeof(struct contato));
    for(;;) {
        menu();
        scanf("%c", &op);
        while(getchar() != '\n');

        switch(op){
            case '1':
                dados = preenche(ldse, dados);
                insereContato(ldse, dados);
                break;

            case '2':
                if(vazia(ldse) == 1)
                    printf("Lista vazia, nao foi possivel remover.\n");

                else {
                    printf("Quem voce quer remover:");
                    gets(nomeNovo);
                    removeContato(ldse, nomeNovo);
                }
                break;
            case '3':
                editarContato(ldse);
                break;
            case '4':
                printf("Digite quem voce quer buscar:\n");
                gets(nomeNovo);

                if(buscaContato(ldse, nomeNovo, dados) == 1)
                    printf("Contato encontrado\nNome: %s: %ld\n", dados->nome, dados->telefone);
                else
                    printf("Contato nao encontrado.\n");
                break;
            case '5':
                imprime(ldse);
                break;
            case '6':
                destruir(ldse);
                break;
            case '7':
                printf("\n_______________\nFinalizando...\n");
                return;
            default:
                printf("Opcao invalida! \n");
        }
    }
    printf("\n");
}


int main()
{
    Lista *ldse = criar();
    // struct contato *dados = (struct contato*)malloc(sizeof(struct contato));
    ler_opcao(ldse);

    return 0;
}


/*
Voce devera implementar uma programa que simule o funcionamento de uma
agenda telefonica. Para isso, implemente um programa principal que tenha
um menu retornavel onde o usuario escolhe dentre as opcoes possíveis.

Requisitos funcionais:

-Funcoes da agenda:

1-Insere contato
2-Busca contato por nome
3-Edita contato (pode alterar o nome ou o telefone)
4-Remove contato pelo nome
5-Apagar todos os contatos
6-Encerrar o programa

-E possivel inserir contatos com o mesmo nome, porem nao e possivel inserir
contatos com o mesmo telefone
-Coloque mensagens para informar ao usuario sempre que houver erros.
Por exemplo, quando o contato nao for inserido, pois ja existe um contato
com o mesmo telefone na agenda, ou quando o contato nao for removido por nao
existir na agenda ninguem com aquele nome

Requisitos nao funcionais:

-Nao e permitido o uso de variaveis globais
-Utilize uma lista dinamica simplesmente encadeada como estrutura de dados,
 implementando as funcoes declaradas em agenda.h.
-Nao e permitido adicionar novas funcoes ou alterar a funcoes existentes em
agenda.h. Se for necessario, crie novas funcoes no programa principal

Opcional: implemente funcoes para carregar e salvar contatos em um arquivo
para nao precisar inserir contatos na mao toda vez que quiser testar o programa
*/
