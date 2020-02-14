#include <time.h>
#include <stdlib.h>
#include "queue.h"
#include "cliente.h"
#include "caixa.h"
#define RAND 5

CAIXA mk_caixa(int n) {
  srand((unsigned)time(NULL));

  CAIXA c = (CAIXA) malloc(sizeof(struct caixa));

  c -> queue = mk_empty_queue(100);
  c -> queueP = mk_empty_queue(100);
  c -> numero = n;
  c -> ready = 0;
  c -> readyP = 0;
  c -> nTotClientes = 0;
  c -> nTotProdutos = 0;
  c -> espera = 0;
  c -> velocidade = rand() % RAND + 1;

  return c;
}

void disponivel(int v, CAIXA c) {
  c -> ready = v;
}

void disponivelP(int v, CAIXA c) {
  c -> readyP = v;
}

void cliente_atendido(CAIXA c) {
  c -> nTotClientes++;
}

void actualiza_produtos(int p, CAIXA c) {
  c -> nTotProdutos+=p;
}

void actualiza_espera(int v, CAIXA c) {
  c -> espera+=v;
}

CAIXA coloca_cliente(CAIXA c, CLIENT cl) {
  if(cl -> priority == 0)
    enqueue(cl, c -> queueP);
  else
    enqueue(cl, c -> queue);

  return c;
}

CLIENT remove_cliente(CAIXA c) {
  CLIENT aux = dequeue(c -> queue);
  return aux;
}

CLIENT remove_clienteP(CAIXA c) {
  CLIENT aux = dequeue(c -> queueP);
  return aux;
}

QUEUE fila_caixa(CAIXA c) {
  return c -> queue;
}

QUEUE fila_caixaP(CAIXA c) {
  return c -> queueP;
}

int numero(CAIXA c) {
  return c -> numero;
}

int pronta(CAIXA c) {
  return c -> ready;
}

int prontaP(CAIXA c) {
  return c -> readyP;
}

int clientes(CAIXA c) {
  return c -> nTotClientes;
}

int produtos(CAIXA c) {
  return c -> nTotProdutos;
}

BOOL caixas_cheias(CAIXA box[], int size) {
  for(int i = 0; i < size; i++)
    if(!queue_is_empty(box[i] -> queue) || !queue_is_empty(box[i] -> queueP))
      return TRUE;

  return FALSE;
}

int espera(CAIXA c) {
  return c -> espera;
}

int tempo_processamento(CAIXA c) {
  return c -> velocidade;
}

BOOL vazia(CAIXA c) {
  return queue_is_empty(c -> queue);
}

BOOL vaziaP(CAIXA c) {
  return queue_is_empty(c -> queueP);
}

void mostra_caixas(CAIXA box[], int size) {
  for(int i = 0; i < size; i++) {
    print_queue(box[i] -> queue);
    printf(" P: ");
    print_queue(box[i] -> queueP);
    printf("\n");
  }
  printf("\n");
}

void processa_resultados(CAIXA box[], int size) {
  for(int i = 0; i < size; i++) {
    printf("\nCaixa %d -> \t\t%d Produtos por ciclo\n", numero(box[i]), tempo_processamento(box[i]));

    if(clientes(box[i]) != 0)
      printf("%d Clientes atendidos\tMédia: %.f produtos/cliente\n", clientes(box[i]), (float)produtos(box[i]) / (float)clientes(box[i]));

    else
      printf("%d Clientes atendidos\n", clientes(box[i]));
  }
}

void trata_clientes(int passo, CAIXA lista_caixas[], int size) {

  for(int i = 0; i < size; i++) {

    if(queue_is_empty(lista_caixas[i] -> queueP)) {
      disponivelP(passo, lista_caixas[i]);
      if(queue_is_empty(lista_caixas[i] -> queue))
        disponivel(passo, lista_caixas[i]);
      else
        trata_primeiro(passo, lista_caixas[i]);
    }
    else
      trata_primeiroP(passo, lista_caixas[i]);
    }
}

void trata_primeiro(int p, CAIXA caixa) {
  int espera, processados;

  CLIENT cliente;

  cliente = peek(caixa -> queue);
  espera = p - pronta(caixa);
  processados = espera * tempo_processamento(caixa);

  if(processados >= get_items(cliente)) {
    disponivel(p + 1, caixa);
    cliente_atendido(caixa);
    actualiza_produtos(get_items(cliente), caixa);
    actualiza_espera(p - get_entrada(cliente), caixa);
    cliente = remove_cliente(caixa);

    printf("--> Cliente atendido na caixa %d\n\n", numero(caixa));
  }
}

/*void trata_clientesP(int passo, CAIXA lista_caixas[], int size) {

  for(int i = 0; i < size; i++) {

    if(queue_is_empty(lista_caixas[i] -> queueP))
      disponivelP(passo, lista_caixas[i]);

    else
      trata_primeiroP(passo, lista_caixas[i]);
  }
}*/

void trata_primeiroP(int p, CAIXA caixa) {
  int espera, processados;

  CLIENT cliente;

  cliente = peek(caixa -> queueP);
  espera = p - prontaP(caixa);
  processados = espera * tempo_processamento(caixa);

  if(processados >= get_items(cliente)) {
    disponivelP(p + 1, caixa);
    cliente_atendido(caixa);
    actualiza_produtos(get_items(cliente), caixa);
    actualiza_espera(p - get_entrada(cliente), caixa);
    cliente = remove_clienteP(caixa);

    printf("--> Cliente atendido na caixa %d (***Prioridade***)\n\n", numero(caixa));
  }
}
