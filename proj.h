//
// Created by Sebastian on 02/10/2023.
//

#ifndef PROJETO_2_PROJ_H
#define PROJETO_2_PROJ_H

typedef struct {
    char nome[20];
    char cpf[10];
    char tipodeconta[5];
    float valorinicial;
    char senha[10];
}Cliente;
typedef struct {
    Cliente clientes[1000];
    int qtd;
} ListaDeClientes;

int criarCliente(ListaDeClientes *lc);
int apagarCliente(ListaDeClientes *lc);
int listarClientes(ListaDeClientes lc);
int debitarCliente(ListaDeClientes *lc);
int depositoCliente(ListaDeClientes *lc);
int transferenciaCliente(ListaDeClientes *lc);
void printMenu();
int salvarLista(ListaDeClientes lc,char nome[]);
int carregarLista(ListaDeClientes *lc, char nome[]);


#endif //PROJETO_2_PROJ_H