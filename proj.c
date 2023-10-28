//
// Created by Sebastian on 02/10/2023.
//

#include "proj.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printMenu(){
    printf("Menu:\n");
    printf("1. Criar Cliente\n");
    printf("2. Apagar Cliente\n");
    printf("3. Listar Clientes\n");
    printf("4. Debitar Cliente\n");
    printf("5. Depositar Cliente\n");
    printf("6. Extrato Cliente\n");
    printf("7. Transferencia Cliente\n");

}/*
void addEntryToExtrato(ListaDeClientes *lc, const char *descricao, double valor, double taxa) {
    if (lc->clientes->qtdExtrato < 50) {
        *//*strcpy(lc->clientes->extrato[lc->clientes->qtdExtrato].descricao, descricao);*//*
        lc->clientes->extrato[lc->clientes->qtdExtrato].valor = valor;
        lc->clientes->extrato[lc->clientes->qtdExtrato].taxa = taxa;
        lc->clientes->qtdExtrato++;
    } else {
        printf("Transaction history full. Cannot add more entries.\n");
    }
}*/
int salvarLista(ListaDeClientes lc, char nome[]){ // Abrindo o arquivo no modo WB
    FILE *f= fopen("clientes", "wb");
    //

    if(f==NULL){
        return 1;
    }
    // Escrevendo a lista atualizada no arquivo
    fwrite(&lc, sizeof(ListaDeClientes), 1, f);
    //

    // Fechando o arquivo
    fclose(f);
    //

    // Indicação de Sucesso
    return 0;
}

int carregarLista(ListaDeClientes *lc,char nome[]){   // Abrindo o arquivo como read
    FILE *f = fopen("clientes", "rb");
    //
    if(f==NULL)
        return 1;

    //Comando para leitura de cada Tarefa dentro da ListaDeTarefas no endereço de lt
    fread(lc,sizeof(ListaDeClientes ),1,f);
    //

    //Fecha o arquivo
    fclose(f);
    //

    // Indicação de Sucesso
    return 0;
}

// Função 1
int criarCliente(ListaDeClientes *lc){

    // Variáveis locais em formato struct
    char nome[20];
    char cpf[10];
    char tipodeconta[5];
    float valorinicial;
    char senha[10];
    //

    // Abrindo o arquivo
    FILE *f = fopen("arquivo.bin", "ab");
    //

    // Se o Arquivo não é encontrado retorna um código de erro
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    //

    Cliente novocliente;

    // Pedindo Informações
    printf("Escreva seu Nome: \n");
    scanf("%s",novocliente.nome);

    printf("Informe seu CPF: \n");
    scanf("%s",novocliente.cpf);

    printf("Que tipo de conta gostaria (Comum ou Plus): \n");
    scanf("%s",novocliente.tipodeconta);

    printf("Qual sera o Valor Inicial depositado: \n");
    scanf("%f",&novocliente.valorinicial);

    printf("Escreva sua Senha: \n");
    scanf("%s",novocliente.senha);
    //

    // Contando o número de tarefas
    lc->clientes[lc->qtd] = novocliente;
    lc->qtd++;
    //

    return 0;
}

// Função 2
int apagarCliente(ListaDeClientes *lc) {
    char cpfDigitado[12];
    char senhaDigitada[11];
    int clienteEncontrado = 0; // Flag para indicar se o cliente foi encontrado

    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);
    printf("Digite a Senha: ");
    scanf("%s", senhaDigitada);

    for (int i = 0; i < lc->qtd; i++) {
        if (strcmp(cpfDigitado, lc->clientes[i].cpf) == 0 && strcmp(senhaDigitada, lc->clientes[i].senha) == 0) {
            // Se o CPF e a Senha estiverem corretos, apague o cliente
            for (int j = i; j < lc->qtd - 1; j++) {
                lc->clientes[j] = lc->clientes[j + 1];
            }
            lc->qtd--;
            clienteEncontrado = 1;
            printf("Cliente apagado com sucesso!\n");
            break; // Não é necessário procurar mais
        }
    }
return 0;}

// Função 3
int listarClientes(ListaDeClientes lc) { // função 3
    printf("Lista de Clientes: %d\n", lc.qtd);

    for (int i = 0; i < lc.qtd; i++) {
        printf("-----------------------\n");
        printf("Nome: %s\n", lc.clientes[i].nome);
        printf("CPF: %s\n", lc.clientes[i].cpf);
        printf("Tipo De Conta: %s\n", lc.clientes[i].tipodeconta);
        printf("Valor: %.2f\n", lc.clientes[i].valorinicial);
        printf("Senha: %s\n", lc.clientes[i].senha);
        printf("-----------------------\n");
    }
    return 0;
}

// Função 4
int debitarCliente(ListaDeClientes *lc) {
    char cpfDigitado[12];
    char senhaDigitada[11];
    double valorDebito,taxa;
    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);
    printf("Digite a Senha: ");
    scanf("%s", senhaDigitada);
    printf("Digite o valor a ser debitado: ");
    scanf("%lf", &valorDebito);

    int clienteEncontrado = 0;

    for (int i = 0; i < lc->qtd; i++) {
        if (strcmp(cpfDigitado, lc->clientes[i].cpf) == 0 && strcmp(senhaDigitada, lc->clientes[i].senha) == 0) {
            // Se o CPF e a Senha estiverem corretos, debite do cliente
            if (strcmp("comum",lc->clientes[i].tipodeconta) == 0){
                taxa = 0.05* valorDebito;
                if(lc->clientes[i].valorinicial + taxa - valorDebito >=-1000){
                    lc->clientes[i].valorinicial -= valorDebito + taxa;

                }
            }
            if(strcmp("plus", lc->clientes[i].tipodeconta) == 0){
                taxa = 0.03* valorDebito;
                printf("%d", taxa);
                if(lc->clientes[i].valorinicial + taxa - valorDebito >=-5000){
                    lc->clientes[i].valorinicial -= valorDebito + taxa;
                    lc->clientes[i].valorinicial -= (valorDebito + taxa);
                    printf("Debitou, %f, da sua conta com sucesso \n", valorDebito);
                }
            }
            else {
                printf("Saldo insuficiente para debitar este valor.\n");
            }
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente não encontrado ou CPF/Senha incorretos.\n");
    }

    return 0;
}

// Função 5
int depositoCliente(ListaDeClientes *lc) {
    char cpfDigitado[12];
    float valordeposito;


    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);
    printf("Digite o valor a ser depositado: ");
    scanf("%f", &valordeposito);

    int clienteEncontrado = 0;

    for (int i = 0; i < lc->qtd; i++) {
        if (strcmp(cpfDigitado, lc->clientes[i].cpf) == 0) {
            // Se o CPF estiver correto, deposite na conta do cliente
            lc->clientes[i].valorinicial += valordeposito;
            printf("Valor depositado com sucesso!\n");
            clienteEncontrado = 1;
            break; // Exit the loop once the client is found and updated
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente não encontrado ou CPF incorreto.\n");
    }

    return 0;
}


// Função 6