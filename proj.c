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
    printf("7. Transferencia Cliente\n");}


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
    int taxa[50];
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

    printf("Informe seu CPF de 11 digitos: \n");
    scanf("%s",novocliente.cpf);
    // Verificar se o CPF tem o tamanho correto
    while (strlen(novocliente.cpf) != 11) {
        printf("O CPF deve ter 11 digitos. Informe seu CPF novamente: \n");
        scanf("%s", novocliente.cpf);
    }

    printf("Que tipo de conta gostaria (Comum ou Plus): \n");
    scanf("%s",novocliente.tipodeconta);

    printf("Qual sera o Valor Inicial depositado: \n");
    scanf("%f",&novocliente.valorinicial);
    //Check para o valorinicial ser maior que 0
    while (novocliente.valorinicial <= 0) {
        printf("O valor inicial deve ser maior que zero. Informe o Valor Inicial novamente: \n");
        scanf("%f", &novocliente.valorinicial);
    }

    printf("Escreva sua Senha (com no maximo 9 digitos): \n");
    scanf("%s",novocliente.senha);
    //

    // Adicionando o cliente e aumentando a quantidade de clientes
    lc->clientes[lc->qtd] = novocliente;
    lc->qtd++;
    //
    return 0;
}

// Função 2 para apagar o cliente
int apagarCliente(ListaDeClientes *lc) {
    char cpfDigitado[12];
    char senhaDigitada[11];
    int clienteEncontrado = 0; // Flag para indicar se o cliente foi encontrado

    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);
    printf("Digite a Senha: ");
    scanf("%s", senhaDigitada);

    //Comparacao dos dados do cliente usando string compare
    for (int i = 0; i < lc->qtd; i++) {
        if (strcmp(cpfDigitado, lc->clientes[i].cpf) == 0 && strcmp(senhaDigitada, lc->clientes[i].senha) == 0) {
            // Se o CPF e a Senha estiverem corretos, apague o cliente
            for (int j = i; j < lc->qtd - 1; j++) {
                lc->clientes[j] = lc->clientes[j + 1];
            }
            lc->qtd--;
            clienteEncontrado = 1;
            printf("Cliente apagado com sucesso!\n");
            break; // Fecha o loop e afirma que o cliente foi encontrado
        }
    }
    if (!clienteEncontrado) {
        printf("Cliente não encontrado ou CPF/Senha incorretos.\n"); //Mensagem de Erro
    }
return 0;}

// Função 3
int listarClientes(ListaDeClientes lc) {
    printf("Lista de Clientes: %d\n", lc.qtd);

    //Itera sobre os clientes com o index i e printa as informacoes uma por uma
    for (int i = 0; i < lc.qtd; i++) {
        printf("-----------------------\n");
        printf("Nome: %s\n", lc.clientes[i].nome);
        printf("CPF: %s\n", lc.clientes[i].cpf);
        printf("Tipo De Conta: %s\n", lc.clientes[i].tipodeconta);
        printf("Valor: %.2f\n", lc.clientes[i].valorinicial);
        printf("-----------------------\n");
    }
    return 0;
}

// Função 4: Debitar cliente
int debitarCliente(ListaDeClientes *lc) {
    char cpfDigitado[12];
    char senhaDigitada[11];
    float valorDebito,taxa;
    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);
    printf("Digite a Senha: ");
    scanf("%s", senhaDigitada);
    printf("Digite o valor a ser debitado: ");
    scanf("%lf", &valorDebito);

    int clienteEncontrado = 0;

    //Procura o CPF e a senha do cliente e as compara com as do arquivo
    for (int i = 0; i < lc->qtd; i++) {
        if (strcmp(cpfDigitado, lc->clientes[i].cpf) == 0 && strcmp(senhaDigitada, lc->clientes[i].senha) == 0) {
            // Se o CPF e a Senha estiverem corretos, debite do cliente, checkando antes o tipo da conta
            if (strcmp("comum",lc->clientes[i].tipodeconta) == 0){
                //Aplica o valor da taxa
                taxa = 0.05* valorDebito;
                if(lc->clientes[i].valorinicial + taxa - valorDebito >=-1000){
                    lc->clientes[i].valorinicial -= valorDebito + taxa;

                }
            }
            else{
                printf("Saldo insuficiente na conta");
            }
            //Checka o tipo da conta
            if(strcmp("plus", lc->clientes[i].tipodeconta) == 0){
                //Aplica a taxa da conta Plus
                taxa = 0.03* valorDebito;
                printf("%f", taxa);
                //Checka se o valor da conta eh suficientemente alto
                if(lc->clientes[i].valorinicial + taxa - valorDebito >=-5000){
                    lc->clientes[i].valorinicial -= (valorDebito + taxa);
                    printf("Debitou, %f, da sua conta com sucesso \n", valorDebito);
                }else {
                    printf("Saldo insuficiente para debitar este valor.\n");
            }
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
    char senhaDigitada[20];

    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);

    printf("Digite a Senha: ");
    scanf("%s", senhaDigitada);


    int clienteEncontrado = 0;

    for (int i = 0; i < lc->qtd; i++) {
        if (strcmp(cpfDigitado, lc->clientes[i].cpf ) == 0&& strcmp(senhaDigitada, lc->clientes[i].senha ) ==0) {
            printf("Conta validada \n");
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valordeposito);
            // Se o CPF e a senha estiverem corretas, deposite na conta do cliente
            lc->clientes[i].valorinicial += valordeposito;
            printf("Valor depositado com sucesso!\n");
            clienteEncontrado = 1;
            break; // Saida do loop e afirma que o cliente foi encontrado
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente não encontrado ou CPF incorreto.\n");
    }

    return 0;
}


//Funcao 7 Transferencia entre clientes

int transferenciaCliente(ListaDeClientes *lc) {
    char cpfDigitado[12];
    char senhaDigitada[11];
    char cpfDestino[12];
    float valorDebito;
    int remetenteEncontrado = 0; // Variável para verificar se o remetente foi encontrado

    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);
    printf("Digite a Senha: ");
    scanf("%s", senhaDigitada);

    // Verificação do remetente
    for (int i = 0; i < lc->qtd; i++) {
        if (strcmp(cpfDigitado, lc->clientes[i].cpf) == 0 && strcmp(senhaDigitada, lc->clientes[i].senha) == 0) {
            remetenteEncontrado = 1; // Remetente encontrado

            printf("Digite o CPF da conta destino: ");
            scanf("%s", cpfDestino);

            // Verificação do destinatário
            int destinatarioEncontrado = 0;
            for (int j = 0; j < lc->qtd; j++) {
                if (strcmp(cpfDestino, lc->clientes[j].cpf) == 0) {
                    destinatarioEncontrado = 1; // Destinatário encontrado

                    printf("Destinatário encontrado com sucesso.\nDigite o valor a ser debitado na conta destino: ");
                    scanf("%f", &valorDebito);

                    // Processamento da transação
                    if (strcmp("plus", lc->clientes[i].tipodeconta) == 0) {
                        if (lc->clientes[i].valorinicial - valorDebito >= -5000) {
                            lc->clientes[i].valorinicial -= valorDebito;
                            lc->clientes[j].valorinicial += valorDebito;
                            printf("Operação concluída com sucesso");
                        } else {
                            printf("Saldo Insuficiente");
                        }
                    } else if (strcmp("comum", lc->clientes[i].tipodeconta) == 0) {
                        if (lc->clientes[i].valorinicial - valorDebito >= -1000) {
                            lc->clientes[i].valorinicial -= valorDebito;
                            lc->clientes[j].valorinicial += valorDebito;
                            printf("Operação concluída com sucesso");
                        } else {
                            printf("Saldo insuficiente");
                        }
                    }
                    break; // Saia do loop, pois o destinatário foi encontrado e a transação foi realizada
                }
            }

            if (!destinatarioEncontrado) {
                printf("Destinatário não encontrado.");
            }
        }
    }

    if (!remetenteEncontrado) {
        printf("CPF ou senha incorretos.");
    }

    return 0;
}
