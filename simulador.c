#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cliente.h"
#include "caixa.h"

void simulador(int afluencia, int apetencia, int n_caixas, int n_ciclos) {
  int j, produtos, rdm, rdmP, caixa_escolhida;

  CAIXA* supermercado = (CAIXA*)malloc(sizeof(CAIXA) * n_caixas);
  CLIENT c;

  srand((unsigned)time(NULL));

  for(int i = 0; i < n_caixas; i++) {
    supermercado[i] = mk_caixa(i + 1);
  }

  for(j = 1; j < n_ciclos + 1; j++) {
    printf("\n** CICLO %d **\n", j);

    trata_clientes(j, supermercado, n_caixas);

    rdm = rand() % 30;

    if(rdm <= (afluencia / 5)) {
      produtos = rand() % (3 * apetencia) + 1;

      c = mk_client();
      rdmP = rand() % 5;
      add_client(produtos, j, c, rdmP);
      if(rdmP == 0)
        printf("--> Criado cliente com %d produtos. (Prioridade!)\n\n", produtos);
      else
        printf("--> Criado cliente com %d produtos.\n\n", produtos);
      caixa_escolhida = rand() % n_caixas + 1;
      supermercado[caixa_escolhida - 1] = coloca_cliente(supermercado[caixa_escolhida - 1], c);
    }

    mostra_caixas(supermercado, n_caixas);
  }

  printf("\n*~*~*~*~*~*~*~*~*~*\n");
  printf("*\t\t  *\n");
  printf("* FECHO DE CAIXAS *\n");
  printf("*\t\t  *\n");
  printf("*~*~*~*~*~*~*~*~*~*\n\n");

  j = n_ciclos + 1;

  while(caixas_cheias(supermercado, n_caixas)) {
    printf("\n** CICLO %d **\n", j);

    trata_clientes(j, supermercado, n_caixas);
    mostra_caixas(supermercado, n_caixas);

    j++;
  }

  processa_resultados(supermercado, n_caixas);
}
