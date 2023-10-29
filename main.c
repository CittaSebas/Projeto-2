#include <stdio.h>
#include "proj.h"


int main() {
    int opcao;
    char arquivo[] = "clientes.bin"; // Nome do arquivo para salvar e carregar os dados
    ListaDeClientes lc;
    int cod;

    cod = carregarLista(&lc, arquivo);

    if (cod == 1) {
        lc.qtd = 0; // Inicializa a quantidade de clientes se houver um erro ao carregar
    }
    do {
        printMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                criarCliente(&lc);
                break;
            case 2:
                apagarCliente(&lc);
                break;
            case 3:
                listarClientes(lc);
                break;
            case 4:
                debitarCliente(&lc);
                break;
            case 5:
                depositoCliente(&lc);
                break;
            case 6:
                // Implemente a função de extratoCliente
                break;
            case 7:
                transferenciaCliente(&lc);
                break;
            default:
                printf("Opção não existe\n");
                break;
        }

    } while (opcao != 0);

    cod = salvarLista(lc, arquivo);

    if (cod != 0) {
        printf("Erro ao salvar os dados dos clientes.\n");
    }

    return 0;
}