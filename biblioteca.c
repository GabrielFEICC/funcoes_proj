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

//funcao de debito
void debito(Cliente clientes[], int num_clientes, Operacao operacoes[], int *num_operacoes) {
    //limite de caracteres para cada string, cpf e senha
    char cpf[12];
    char senha[20];
    float valor;

    printf("CPF: ");
    scanf("%s", cpf);

    int i;
    for (i = 0; i < num_clientes; i++) {
        //ira pedir a senha do cliente para fazer um debito
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            printf("senha: ");
            scanf("%s", senha);

            //o cliente escolhera um valor a ser debitado
            if (strcmp(&clientes[i].senha, &senha) == 0) {
                printf("valor a ser debitado: ");
                scanf("%f", &valor);

                //caso a conta do cliente for comum, tera a taxa de 5%
                if (strcmp(&clientes[i].tipo_de_conta, "comum") == 0) {
                    if (clientes[i].saldo - valor >= -1000) {
                        clientes[i].saldo -= valor * 1.05;
                        printf("debitao realizado\n");
                        strcpy(operacoes[*num_operacoes].cpf, cpf);
                        strcpy(&operacoes[*num_operacoes].tipo_de_operacao, "debito");
                        operacoes[*num_operacoes].valor = valor;
                        (*num_operacoes)++;
                    } else {
                        printf("saldo insuficiente\n");
                    }
                    //caso a conta do cliente do plus, tera taxa de 3%
                } else if (strcmp(&clientes[i].tipo_de_conta, "plus") == 0) {
                    if (clientes[i].saldo - valor >= -5000) {
                        clientes[i].saldo -= valor * 1.03;
                        printf("debito realizado\n");
                        strcpy(operacoes[*num_operacoes].cpf, cpf);
                        strcpy(&operacoes[*num_operacoes].tipo_de_operacao, "debito");
                        operacoes[*num_operacoes].valor = valor;
                        (*num_operacoes)++;
                    } else {
                        //caso o cliente nao tenha saldo suficiente
                        printf("saldo insuficiente\n");
                    }
                } else {
                    //caso o tipo de conta estiver errado
                    printf("tipo de conta nao aceita\n");
                }
            } else {
                //caso o cliente tenha errado a senha
                printf("senha errada\n");
            }
            return;
        }
        //caso o cliente erre o cpf
        printf("cliente nao encontrado\n", cpf);
    }
}

//funcao de deposito
void deposito(Cliente clientes[], int num_clientes, Operacao operacoes[], int *num_operacoes){
    //limite de caracteres da string cpf
    char cpf[12];
    float valor;

    printf("CPF: ");
    scanf("%s", cpf);

    int i;
    for (i=0; i< num_clientes; i++){
        //para debitar um valor para um cliente
        if (strcmp(clientes[i].cpf, cpf)==0){
            printf("valor a ser depositado: ");
            scanf("%f",&valor);

            if (valor > 0) {
                //quando o valor debitado for maior que 0, sera debitado com sucesso
                clientes[i]. saldo += valor;
                printf("depositado com sucesso\n");
                strcpy(operacoes[*num_operacoes].cpf,cpf);
                strcpy(&operacoes[*num_operacoes].tipo_de_operacao,"deposito");
                operacoes[*num_operacoes].valor=valor;
                (*num_operacoes)++;
            }else {
                //caso menor que 0, deposito nao sera possivel
                printf("deposito invalido\n");
            }
            return;
        }
    }
    //caso o cliente nao seja encontrado
    printf("cliente nao encontrado\n", cpf);
}

//funcao de transferir
void transferir(Cliente clientes[], int num_clientes, Operacao operacoes[], int *num_operacoes){
    //para limitar os caracteres da string de cpf de origem, senha de origem e cpf de destino
    char cpf_de_origem[12];
    char senha_de_origem[20];
    char cpf_de_destino[12];
    float valor;

    printf("CPF de conta de origem: ");
    scanf("%s", cpf_de_origem);

    int i;
    for (i = 0; i < num_clientes; i++) {
        //para o cliente digitar a sua senha
        if (strcmp(clientes[i].cpf, cpf_de_origem) == 0) {
            printf("senha da conta de origem: ");
            scanf("%s", senha_de_origem);

            //para o cliente desejar o cpf do outro cliente que deseja enviar
            if (strcmp(&clientes[i].senha, &senha_de_origem) == 0) {
                printf("CPF da conta de destino: ");
                scanf("%s", cpf_de_destino);

                int j;
                for (j = 0; j < num_clientes; j++) {
                    //para colocar o valor que deseja transferir para o outro cliente
                    if (strcmp(clientes[j].cpf, cpf_de_destino) == 0) {
                        printf("valor que deseja transferir: ");
                        scanf("%f", &valor);

                        if (valor > 0) {
                            //quando a transferencia for realizada com succeso
                            if (strcmp(&clientes[i].tipo_de_conta, "comum") == 0 | strcmp(&clientes[i].tipo_de_conta, "plus") == 0) {
                                if (clientes[i].saldo >= valor) {
                                    clientes[i].saldo -= valor;
                                    clientes[j].saldo += valor;
                                    printf("transferencia realizada\n");

                                    //quando o cliente da entrada na transferencia, digita o seu cpf e valor
                                    strcpy(operacoes[*num_operacoes].cpf, cpf_de_origem);
                                    strcpy(&operacoes[*num_operacoes].tipo_de_operacao, "transferencia (entrada)");
                                    operacoes[*num_operacoes].valor = valor;
                                    (*num_operacoes)++;

                                    //quando o cliente recebe o dinheiro, acaba a transferencia
                                    strcpy(operacoes[*num_operacoes].cpf, cpf_de_destino);
                                    strcpy(&operacoes[*num_operacoes].tipo_de_operacao, "transferencia (saida)");
                                    operacoes[*num_operacoes].valor = valor;
                                    (*num_operacoes)++;
                                }   else {
                                    //quando o cliente nao tenha o saldo suficiente
                                    printf("saldo insuficiente na conta\n");
                                }
                            }   else {
                                //quando o cliente erra o tipo de conta
                                printf("tipo de conta invalido\n");
                            }
                        } else {
                            //quando digita um valor errado
                            printf("valor de transferencia invalido\n");
                        }
                        return;
                    }
                }
                //quando o cliente nao existe ou errou ao escrever o cpf do cliente
                printf("conta nao encontrada\n");
                return;
            } else {
                //quando erra a sua senha
                printf("senha da conta errada\n");
                return;
            }
        }
    }

}