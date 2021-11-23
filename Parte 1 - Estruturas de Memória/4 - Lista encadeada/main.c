/** Programa que armazena dados de um arquivo CSV em uma lista simplesmente encadeada.
  * (...)
  *
  */

#include <stdio.h>
#include <string.h>
#include "dados.h"
#include "lista_enc.h"
#include "no.h"


int main(){
    lista_enc_t *lista = ler_dados_csv("aeroportos.csv");

    no_t *no;
    no = obter_cabeca(lista);
    aeroporto_st *dado;

    /* Imprima os dados:*/
    while (no != NULL){
        dado = obter_dado(no);
        printf( "%d ,%s ,%s ,%s \n", obter_indice(dado),obter_sigla(dado),obter_cidade(dado),obter_estado(dado));
        no = obter_proximo(no);
    }
    no = obter_cabeca (lista);
    liberar_dados(no);
    free(lista);

    return 0;
}
