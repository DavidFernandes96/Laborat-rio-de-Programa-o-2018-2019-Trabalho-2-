#ifndef _QUEUE
#define _QUEUE

#include "cliente.h"

typedef enum {
  FALSE,
  TRUE
} BOOL;

typedef struct fila {
  int inicio, fim, nmax;
  CLIENT* queue;
} *QUEUE;


//criar fila com capacidade para n inteiros
QUEUE mk_empty_queue(int n);

//colocar valor na fila
void enqueue(CLIENT v, QUEUE q);

//retirar valor na fila
CLIENT dequeue(QUEUE q);

//verificar se a fila está vazia
BOOL queue_is_empty(QUEUE q);

//verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE q);

//liberta fila
void free_queue(QUEUE q);

//imprime fila
void print_queue(QUEUE q);

CLIENT peek(QUEUE q);

//função auxiliar (privada)
void queue_exit_error(char* msg);

#endif
