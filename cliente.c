#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

CLIENT mk_client() {
  CLIENT c = (CLIENT) malloc(sizeof(struct cliente));

  return c;
}

void add_client(int i, int e, CLIENT c, int p) {
  c -> items = i;
  c -> entrada = e;
  c -> priority = p;
}

int get_items(CLIENT c) {
  return c -> items;
}

int get_entrada(CLIENT c) {
  return c -> entrada;
}
