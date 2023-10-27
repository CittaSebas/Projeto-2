//
// Created by Sebastian on 02/10/2023.
//

#include "proj.h"
#include <stdio.h>
int criarCliente(ListaDeClientes *lc){

    // Variáveis locais em formato struct
    char nome[20];
    char cpf[10];
    char tipodeconta[5];
    int valorinicial;
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

    // Pedindo Categoria, Descrição e Prioriade ao usuário
    printf("Escreva seu Nome: \n");
    scanf("%s",novocliente.nome);

    printf("Informe seu CPF: \n");
    scanf("%s",novocliente.cpf);

    printf("Que tipo de conta gostaria (Comum ou Plus): \n");
    scanf("%s",&novocliente.tipodeconta);

    printf("Qual sera o Valor Inicial depositado: \n");
    scanf("%f",&novocliente.valorinicial);

    printf("Escreva sua Senha: \n");
    scanf("%s",&novocliente.senha);
    //

    // Contando o número de tarefas
    lc->clientes[lc->qtd] = novocliente;
    lc->qtd++;
    //

    return 0;
}
void printMenu(){
    printf("Menu:\n");
    printf("1. Criar Cliente\n");
    printf("2. Apagar Cliente\n");
    printf("3. Listar Clientes\n");
    printf("4. Debitar Cliente\n");
    printf("5. Depositar Cliente\n");
    printf("6. Extrato Cliente\n");
    printf("7. Transferencia Cliente\n");

}

int salvarLista(ListaDeClientes lc, char nome[]){ // Abrindo o arquivo no modo WB
    FILE *f= fopen("arquivo.bin", "wb");
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
    return 0;}
//}
int carregarLista(ListaDeClientes *lc,char nome[]){   // Abrindo o arquivo como read
    FILE *f = fopen("arquivo.bin", "rb");
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
    return 0;}

//int listarClientes(ListaDeClientes lc) {
//    int i = 0;
//
//    // Mensagem para o usuário
//    printf("Clientes: \n");
//    //
//
//    //Loop de repetição para leitura de cada Tarefa dentro da ListaDeTarefas no endereço lt
//    while (i < lc.qtd) {
//        printf("-----------------------\n");
//        printf("Numero da Tarefa: %d\n", i);
//        printf("Categoria: %s\n", lc.clientes[i].nome);
//        printf("Descricao: %s\n", lc.clientes[i].cpf);
//        printf("Prioridade: %s\n", lc.clientes[i].tipodeconta);
//        printf("Prioridade: %d\n", lc.clientes[i].valorinicial);
//        i++;
//    }
//    return 0;
//    //
//}

int listarClientes(ListaDeClientes lc) {
    printf("Total number of clients: %d\n", lc.qtd);

    for (int i = 0; i < lc.qtd; i++) {
        printf("-----------------------\n");
        printf("Numero da Tarefa: %d\n", i);
        printf("Categoria: %s\n", lc.clientes[i].nome);
        printf("Descricao: %s\n", lc.clientes[i].cpf);
        printf("Prioridade: %s\n", lc.clientes[i].tipodeconta);
        printf("Prioridade: %d\n", lc.clientes[i].valorinicial);
    }
    return 0;
}

//#include "proj.h"
//#include <stdio.h>
//
//
//int criarTarefa(ListaDeTarefas *lt){
//
//    // Variáveis locais em formato struct
//    char categoria[100];
//    char descricao[300];
//    int prioridade;
//    //
//
//    // Abrindo o arquivo
//    FILE *f = fopen("arquivo.bin", "ab");
//    //
//
//    // Se o Arquivo não é encontrado retorna um código de erro
//    if (f == NULL) {
//        printf("Erro ao abrir o arquivo.\n");
//        return 1;
//    }
//    //
//
//    Tarefa novatarfea;
//
//    // Pedindo Categoria, Descrição e Prioriade ao usuário
//    printf("Escreva sua tarefa: \n");
//    scanf("%s",novatarfea.categoria);
//
//    printf("Descreva sua tarefa: \n");
//    scanf("%s",novatarfea.descricao);
//
//    printf("Qual a prioridade: \n");
//    scanf("%d",&novatarfea.prioriade);
//    //
//
//    // Contando o número de tarefas
//    lt->tarefas[lt->qtd] = novatarfea;
//    lt->qtd++;
//    //
//
//    // Escrevendo a lista atualizada no arquivo
//    fwrite(lt->tarefas, sizeof(Tarefa), lt->qtd, f);
//    //
//
//    // Fechando o arquivo
//    fclose(f);
//    //
//
//    // Indicação de Sucesso
//    return 0;
//    //
//}
//
//
//
//int deletarTarefa(ListaDeTarefas *lt){
//    printf("deletar tarefa\n");
//    return 0;
//}
//int listarTarefas(ListaDeTarefas lt){
//
//    // Abrindo o arquivo
//    FILE *f = fopen("arquivo.bin", "r");
//    //
//
//    // Mensagem para o usuário
//    printf("Tarefas cadastradas: \n");
//    //
//
//    // Creando váriavel de leitura no formato Struct de Tarefa
//    Tarefa tarefalida;
//    //
//
//    //Loop de repetição para leitura de cada Tarefa dentro da ListaDeTarefas no endereço de tarefalida
//    while (fread(&tarefalida,sizeof(Tarefa),1,f)==1){
//        printf("Categoria: %s\n", tarefalida.categoria);
//        printf("Descricao: %s\n", tarefalida.descricao);
//        printf("Prioridade: %d\n", tarefalida.prioriade);
//    }
//    //
//
//    // Fecha o arquivo
//    fclose(f);
//    //
//
//    // Indicação de Sucesso
//    return 0;
//    //
//}
//
//void printMenu(){ printf("Menu:\n");}
