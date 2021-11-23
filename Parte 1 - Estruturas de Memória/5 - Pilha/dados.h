#ifndef DADO_H_INCLUDED
#include "pilha.h"
/* Criação de tipo abstrato dado_t */
typedef struct aeroporto aeroporto_st;

int obter_indice (aeroporto_st * aeroporto);

char *obter_sigla (aeroporto_st * aeroporto);

char *obter_cidade (aeroporto_st * aeroporto);

char *obter_estado (aeroporto_st * aeroporto);

aeroporto_st * criar_dado (int indice, char *sigla, char *cidade, char *estado);

pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo);












#endif
