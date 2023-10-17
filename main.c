// Theo Zago Zimmermann - 22.123.035-2
// Gabriel Lovato Camilo de Campos - 22.123.004-8


#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

//a main funciona para fazer rodar o programa no terminal e mostrar os resultados
//fizemos todas as funcoes no b.c, na main apenas estamos chamando as funcoes para rodar perfeitamente no terminal no arquivo
int main() {
    Cliente clientes[MAX_CLIENTES];
    Operacao operacoes[MAX_OPERACOES];
    int num_clientes = 0;
    int num_operacoes = 0;

    int opcao;
    do {
        //para o cliente escolher a opcao que deseja
        printf("1 - Novo cliente\n");
        printf("2 - Apagar cliente\n");
        printf("3 - Listar clientes\n");
        printf("4 - Debito\n");
        printf("5 - Deposito\n");
        printf("6 - Extrato\n");
        printf("7 - Transferencia entre contas\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        //fizemos todas as funcoes no biblioteca.c, na main apenas estamos chamando as funcoes para rodar perfeitamente no terminal e no arquivo
        switch (opcao) {
            case 1:
                criar_cliente(clientes, &num_clientes);
                break;
            case 2: {
                char cpf[12];
                printf("digite o cpf do cliente que deseja apagar: ");
                scanf("%s", cpf);
                apagar_cliente(clientes, &num_clientes, cpf);
                break;
            }
            case 3:
                listar_cliente(clientes, num_clientes);
                break;
            case 4:
                debito(clientes, num_clientes, operacoes, &num_operacoes);
                break;
            case 5:
                deposito(clientes, num_clientes, operacoes, &num_operacoes);
                break;
            case 6:
                extrato(clientes, num_clientes, operacoes, num_operacoes);
                break;
            case 7:
                transferir(clientes, num_clientes, operacoes, &num_operacoes);
                break;
            case 0:
                //para sair do programa
                printf("saindo do programa\n");
                break;
            default:
                //caso digite um numero errado
                printf("opcao invalida\n");
        }

    } while (opcao != 0);
    return 0;

}
