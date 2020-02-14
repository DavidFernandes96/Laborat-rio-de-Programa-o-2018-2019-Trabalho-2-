#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulador.h"
#include "menu.h"

void input_info(char *opcao) {

  printf("Escolha uma opção: ");
  scanf("%s", opcao);
  printf("\n");

  if(*opcao < '1' || *opcao > '2' || strlen(opcao) > 1) {
    printf("Opção inválida, tente novamente!\n");
    input_info(opcao);
  }
}

void input_menu(char *opcao) {

  printf("Escolha uma opção: ");
  scanf("%s", opcao);
  printf("\n");


  if(*opcao < '1' || *opcao > '3' || strlen(opcao) > 1) {
    printf("Opção inválida, tente novamente!\n");
    input_menu(opcao);
  }
}

void exec() {
  int afluencia, apetencia, n_caixas, n_ciclos;
  char *opcao = malloc(sizeof(char));

  system("clear");

  printf("1) Executar o simulador\n\n");

  do {
    printf("Afluência: ");
    scanf("%d", &afluencia);
    printf("\n");

    if(afluencia <= 0 || afluencia > 100)
      printf("Valor incorreto! Só valores admitidos em [1, 100].\n");

  } while(afluencia <= 0 || afluencia > 100);

  do {
    printf("Apetência: ");
    scanf("%d", &apetencia);
    printf("\n");

    if(apetencia <= 0 || apetencia > 100)
      printf("Valor incorreto! Só valores admitidos em [1, 100].\n");

  } while(apetencia <= 0 || apetencia > 100);

  do {
    printf("Número de caixas: ");
    scanf("%d", &n_caixas);
    printf("\n");

    if(n_caixas <= 0)
      printf("Valor incorreto! Só valores admitidos maiores que 1.\n");

  } while(n_caixas <= 0);

  do {
    printf("Número de ciclos: ");
    scanf("%d", &n_ciclos);
    printf("\n");

    if(n_ciclos <= 0)
      printf("Valor incorreto! Só valores admitidos maiores que 1.\n");

  } while(n_caixas <= 0);

  simulador(afluencia, apetencia, n_caixas, n_ciclos);

  printf("\n\nExecução concluída...\n\n\n");
  printf("1) Menu principal\n");
  printf("2) Sair\n\n");

  input_info(opcao);

  switch(*opcao){
    case '1': {system("clear"); menu(); break;};
    case '2': {system("clear"); exit(0);}
    default:{*opcao = '0';};
  }
}

void info() {
  char *opcao = malloc(sizeof(char));

  system("clear");

  printf("2) Informações do projeto\n\n");

  printf("Instituição:\n");
  printf("Faculdade de Ciências da Universidade do Porto\n\n");

  printf("Cadeira:\n");
  printf("Laboratório de Programação\n\n");

  printf("Docente:\n");
  printf("Prof. Mário Florido\n\n");

  printf("Autores do projeto:\n");
  printf("David Fernandes -> up201605791\n");
  printf("Tiago Bessa -> up201606796\n\n\n");

  printf("1) Menu principal\n");
  printf("2) Sair\n\n");

  input_info(opcao);

  switch(*opcao){
    case '1': {system("clear"); menu(); break;};
    case '2': {system("clear"); exit(0);}
    default:{*opcao = '0';};
  }
}

void menu() {
  char *opcao = malloc(sizeof(char));

  system("clear");

  printf("** Menu **\n\n");
  printf("1) Executar o simulador do Supermercado\n");
  printf("2) Informações do projeto\n");
  printf("3) Sair\n\n");

  input_menu(opcao);

  switch(*opcao){
    case '1': {system("clear"); exec(); break;};
    case '2': {system("clear"); info(); break;};
    case '3': {system("clear"); exit(0);};
    default:{*opcao = '0';};
  }
}
