#ifndef _CLIENT
#define _CLIENT

typedef struct cliente {
  int items;
  int entrada;
  int priority; //0 -> Urgente | 1,2,3,4 -> Nao urgente
} *CLIENT;

CLIENT mk_client();

void add_client(int i, int e, CLIENT c, int p);

int get_items(CLIENT c);

int get_entrada(CLIENT c);

#endif
