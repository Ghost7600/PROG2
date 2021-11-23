#ifndef DADO_H_INCLUDED
#include "lista_enc.h"
#include "no.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;
typedef struct aeroporto aeroporto_st;

lista_enc_t *ler_dados_csv(char *nome_do_arquivo);
int obter_indice (aeroporto_st * aeroporto);
char *obter_sigla (aeroporto_st * aeroporto);
char *obter_cidade (aeroporto_st * aeroporto);
char *obter_estado (aeroporto_st * aeroporto);
void liberar_dados(no_t *cabeca);










#endif
