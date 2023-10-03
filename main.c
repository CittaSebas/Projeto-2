#include <stdio.h>
#include "proj.h"

int main() {

    int cod;
    char arquivo[] = "clientes";
    ListaDeClientes lc;

    cod = carregarLista(&lc,arquivo);
    if (cod == 1)
        lc.qtd = 0;

    int opcao;

    do{
        printMenu();
        scanf("%d", &opcao);
        printf("%d\n",opcao);

        if(opcao ==0){}
        else if(opcao ==1){
            criarCliente(&lc);
        }
        else if(opcao ==2){
            apagarCliente(&lc);
        }
        else if(opcao ==3){
            listarClientes(lc);
        }
        else if(opcao ==4){
            debitarCliente(&lc);
        }
        else if(opcao ==5){
            depositaCliente(&lc);
        }
        else if(opcao ==6){
            extratoCliente(&lc);
        }
        else if(opcao ==7){
            transferenciaCliente(&lc);
        }
        else{
            printf("Opcao nao existe\n");
        }

    }while(opcao !=0);

    cod = salvarLista(lc,arquivo);
    if (cod !=0)
        printf("Erro ao salvar as tarefas");

}