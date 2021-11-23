#ifndef AEROPORTOS_H_INCLUDED
#define DEBUG

/* Criação de tipo abstrato aeroporto_st */
typedef struct aeroporto aeroporto_st;


aeroporto_st * criar_aeroporto (int indice, char *sigla, char *cidade, char *estado);
int obter_indice (aeroporto_st * aeroporto);
char *obter_sigla (aeroporto_st * aeroporto);
char *obter_cidade (aeroporto_st * aeroporto);
char *obter_estado (aeroporto_st * aeroporto);
void  liberar_dados(aeroporto_st **paeroportos,int qtd);


/* Outras funções aqui: fazer os comentários */

aeroporto_st **ler_dados_csv(char *nome_arquivo, int *qlinhas);


#endif
