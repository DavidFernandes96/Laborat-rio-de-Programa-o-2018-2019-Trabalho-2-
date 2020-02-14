#ifndef _CAIXA
#define _CAIXA

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct caixa {
  QUEUE queue;
  QUEUE queueP;
  int numero;
  int ready;
  int readyP;
  int nTotClientes;
  int nTotProdutos;
  int espera;
  int velocidade;
} *CAIXA;

CAIXA mk_caixa(int n);

void disponivel(int v, CAIXA c);

void cliente_atendido(CAIXA c);

void actualiza_produtos(int p, CAIXA c);

void actualiza_espera(int v, CAIXA c);

CAIXA coloca_cliente(CAIXA c, CLIENT cl);

CLIENT remove_cliente(CAIXA c);

CLIENT remove_clienteP(CAIXA c);

QUEUE fila_caixa(CAIXA c);

QUEUE fila_caixaP(CAIXA c);

int numero(CAIXA c);

int pronta(CAIXA c);

int prontaP(CAIXA c);

int clientes(CAIXA c);

int produtos(CAIXA c);

BOOL caixas_cheias(CAIXA box[], int size);

int espera(CAIXA c);

int tempo_processamento(CAIXA c);

BOOL vazia(CAIXA c);

BOOL vaziaP(CAIXA c);

void mostra_caixas(CAIXA box[], int size);

void processa_resultados(CAIXA box[], int size);

void trata_clientes(int passo, CAIXA lista_caixas[], int size);

void trata_primeiro(int p, CAIXA caixa);

void trata_primeiroP(int p, CAIXA caixa);

#endif
