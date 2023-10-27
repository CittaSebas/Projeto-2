//
// Created by Sebastian on 02/10/2023.
//

#ifndef PROJETO_2_PROJ_H
#define PROJETO_2_PROJ_H

typedef struct {
    char nome[20];
    char cpf[10];
    char tipodeconta[5];
    int valorinicial;
    char senha[10];
} Cliente;

typedef struct {
    Cliente clientes[1000];
    int qtd;
} ListaDeClientes;

int criarCliente(ListaDeClientes lt);
int apagarCliente(const chararquivo, const char cpf, const charsenha);
int listarClientes(ListaDeClientes lt);
int debitarCliente(ListaDeClientes lt);
int depositaCliente(ListaDeClienteslt);
int extratoCliente(ListaDeClientes lt);
int transferenciaCliente(ListaDeClienteslt);



void printMenu();
int salvarLista(ListaDeClientes lt,char nome[]);
int carregarLista(ListaDeClientes *lt, char nome[]);

#endif //PROJETO_2_PROJ_H