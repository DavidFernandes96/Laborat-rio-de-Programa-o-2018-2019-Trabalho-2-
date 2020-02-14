#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "cliente.h"

//criar fila com capacidade para n inteiros
QUEUE mk_empty_queue(int n) {
  QUEUE q = (QUEUE) malloc(sizeof(struct fila));
  if(q == NULL)
    queue_exit_error("Sem memória");

  q -> queue =  (CLIENT*)malloc(sizeof(CLIENT) * n);
  if(q -> queue == NULL)
    queue_exit_error("Sem memória");

  q -> nmax = n;
  q -> inicio = -1;
  q -> fim = 0;

  return q;
}

//libertar fila
void free_queue(QUEUE q) {
  if(q != NULL) {
    free(q -> queue);
    free(q);
  }

  else
    queue_exit_error("Fila mal construída");
}

//colocar valor na fila
void enqueue(CLIENT v, QUEUE q) {
  if(queue_is_full(q))
    queue_exit_error("Fila sem lugar");

  if(q -> queue == NULL)
    queue_exit_error("Fila mal construída");

  if(queue_is_empty(q))
    q -> inicio = q -> fim; //fila fica com um elemento

  q -> queue[q -> fim] = v;
  q -> fim = (q -> fim+1) % (q -> nmax);
}

//retirar valor na fila
CLIENT dequeue(QUEUE q) {
  CLIENT aux;

  if(queue_is_empty(q))
    queue_exit_error("Fila sem valores");

  if(q -> queue == NULL)
    queue_exit_error("Fila mal construída");

  aux = q -> queue[q -> inicio];
  q -> inicio = (q -> inicio + 1) % (q -> nmax);

  if(q -> inicio ==  q -> fim) {  //se só tinha um elemento
    q -> inicio = -1;
    q -> fim = 0;
  }

  return aux;
}

//verificar se a fila está vazia
BOOL queue_is_empty(QUEUE q) {
  if(q == NULL)
    queue_exit_error("Fila mal construída");

  if(q -> inicio == -1)
    return TRUE;

  return FALSE;
}

//verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE q) {
  if(q == NULL)
    queue_exit_error("Fila mal construída");

  if(q -> fim == q -> inicio)
    return TRUE;

  return FALSE;
}

//imprime fila
void print_queue(QUEUE q) {
  int i;

  if(queue_is_empty(q)) {
    printf("[]");

    return;
  }

  printf("[");

  for(i = q -> inicio; i < q -> fim - 1; i++) {
    printf("(%d, ", q -> queue[i] -> items);
    printf("%d), ", q -> queue[i] -> entrada);
  }

  printf("(%d, ", q -> queue[i] -> items);
  printf("%d)]", q -> queue[i] -> entrada);
}

CLIENT peek(QUEUE q) {
  return q -> queue[q -> inicio];
}

void queue_exit_error(char* msg) {
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}
