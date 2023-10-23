//
// Created by unifgcampo on 10/10/2023.
//
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

//funcao de criar cliente
void criar_cliente(Cliente clientes[], int *num_clientes){
    if (*num_clientes < MAX_CLIENTES) {
        Cliente novo;
        //pedindo o nome
        printf("Nome: ");
        //para escrever o nome com funcao scanf
        scanf("%s", novo.nome);
        //pedindo o cpf
        printf("CPF: ");
        //para escrever o cpf com funcao scanf
        scanf("%s", novo.cpf);
        //pedindo o tipo de conta
        printf("Tipo de contas (comum ou plus): ");
        //para escrever o tipo de conta com funcao scanf
        scanf("%s", novo.tipo_de_conta);
        //pedindo o valor inicial da conta
        printf("Valor inicial da conta: ");
        //para escrever o valor inicial com funcao scanf
        scanf("%f", &novo.saldo);
        //pedindo a senha do cliente
        printf("Senha do cliente: ");
        //para escrever a senha com funcao scanf
        scanf("%s", novo.senha);

        clientes[*num_clientes] = novo;
        //cliente adicionado
        (*num_clientes)++;
        //cliente criado com o sucesso
        printf("Cliente cadastrado com sucesso\n");
    }  else {
        //quando ja possui o maximo de clientes
        printf("Maximo de cliente atingido\n");
    }
}

//funcao de apagar cliente
void apagar_cliente(Cliente clientes[], int *num_clientes, const char *cpf) {
    //comandos usados para apgar o clientes
    int i;
    for (i = 0; i < *num_clientes; i++) {
        //usado para apagar o cliente atraves do cpf dele
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            for (int j = i; j < (*num_clientes - 1); j++) {
                clientes[j] = clientes [j + 1];
            }
            //cliente removido
            (*num_clientes)--;
            printf("Cliente apagado com sucesso\n", cpf);
            return;
        }
    }//quando nao encontra o cpf no banco
    printf("Cliente nao encontrado\n", cpf);
}

//funcao de listar o cliente
void listar_cliente(Cliente clientes[], int num_clientes) {
    //quando nao possui nenhum cliente cadastrado, ira retornar ao menu
    if (num_clientes == 0) {
        printf("nao possui cliente cadastrado\n");
        return;
    }//ira mostrar as listas do cliente cadastrados
    printf("Lista de clientes: \n");
    for (int i = 0; i < num_clientes; i++) {
        //esse print ira mostrar o nome do cliente
        printf("Nome: %s\n", clientes[i].nome);
        //esse print ira mostrar o cpf do cliente
        printf("CPF: %s\n", clientes[i].cpf);
        //esse print ira mostrar o tipo de conta do cliente
        printf("Tipo de conta: %s\n", clientes[i].tipo_de_conta);
        //esse print ira mostrar o saldo do cliente
        printf("saldo: %.2f\n", clientes[i].saldo);
    }
}