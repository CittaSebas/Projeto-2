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
} Cliente;
//GITHUB
typedef struct {
    Cliente clientes[1000];
    int qtd;
} ListaDeClientes;

int criarCliente(ListaDeClientes *lc);
int apagarCliente(ListaDeClientes *lc);
int listarClientes(ListaDeClientes lc);
int debitarCliente(ListaDeClientes *lc);
int depositoCliente(ListaDeClientes *lc);
int extratoCliente(ListaDeClientes lt);
int transferenciaCliente(ListaDeClientes lc);



void printMenu();
int salvarLista(ListaDeClientes lt,char nome[]);
int carregarLista(ListaDeClientes *lt, char nome[]);

#endif //PROJETO_2_PROJ_H