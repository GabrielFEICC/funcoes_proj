//
// Created by unifgcampo on 10/10/2023.
//

#ifndef PROJETO2_BIBLIOTECA_H
#define PROJETO2_BIBLIOTECA_H
// para definir o limite de clientes e de operacoes
#define MAX_CLIENTES 1000
#define MAX_OPERACOES 100

//uma struct para escrever seu nome, cpf, tipo de conta, saldo e senha
typedef struct{
    char nome[100];
    char cpf[12];
    char tipo_de_conta[8];
    float saldo;
    char senha[20];
} Cliente;

//outra struct para escolher a operacao que deseja
typedef struct{
    char cpf[12];
    char tipo_de_operacao[20];
    float valor;
} Operacao;

//funcao de criar cliente para usar na biblioteca.c
void criar_cliente(Cliente clientes[], int *num_clientes);
//funcao de apagar cliente para usar na biblioteca.c
void apagar_cliente(Cliente clientes[], int *num_clientes, const char *cpf);
//funcao de listar cliente para usar na biblioteca.c
void listar_cliente(Cliente clientes[], int num_clientes);
//funcao de debito para usar na biblioteca.c
void debito(Cliente clientes[], int num_clientes, Operacao operacoes[], int *num_operacoes);
//funcao de depositar para usar na biblioteca.c
void deposito(Cliente clientes[], int num_clientes, Operacao operacoes[], int *num_operacoes);
//funcao de extrato para usar na biblioteca.c
void extrato(Cliente clientes[], int num_clientes, Operacao operacoes[], int num_operacoes);
//funcao de transferir para usar na biblioteca.c
void transferir(Cliente clientes[], int num_clientes, Operacao operacoes[], int *num_operacoes);



#endif //PROJETO2_BIBLIOTECA_H