/** Programa que armazena e lê e manipula dados em uma pilha.
  *         Kenner Marqueti Couto, orientado por Renan Augusto Starke
  *         Finalizado em: Sábado, 20 de novembro de 2021;
  */

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"



int main(){
    pilha_t *pilha = ler_dados_csv_pilha("aeroportos.csv");



    /* Imprima os dados:*/
    while (pilha_vazia(pilha)== 0){



    aeroporto_st *dado = pop(pilha);
      printf( "%d ,%s ,%s ,%s \n", obter_indice(dado),obter_sigla(dado),obter_cidade(dado),obter_estado(dado));
      free(dado);





    }

    libera_pilha(pilha);

    return 0;
}
