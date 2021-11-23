
/* Descrever/documentar módulo */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "pilha.h"
#include "dados.h"

struct aeroporto
{
    int indice;
    char sigla[4];
    char cidade[128];
    char estado [128];

};

int obter_indice (aeroporto_st * aeroporto)
{
    return aeroporto-> indice;
}

char *obter_sigla (aeroporto_st * aeroporto)
{
    return aeroporto-> sigla;
}

char *obter_cidade (aeroporto_st * aeroporto)
{
    return aeroporto-> cidade;
}

char *obter_estado (aeroporto_st * aeroporto)
{
    return aeroporto-> estado;
}


aeroporto_st * criar_dado (int indice, char *sigla, char *cidade, char *estado)
{

    aeroporto_st * novo_aeroporto = malloc(sizeof(struct aeroporto));



    /* Novos dados são copiados para nova estrutura vinda do malloc */
    novo_aeroporto -> indice = indice;
    strncpy(novo_aeroporto -> sigla,sigla,4);
    strncpy(novo_aeroporto -> cidade,cidade,128);
    strncpy(novo_aeroporto -> estado,estado,128);



    return novo_aeroporto;
}



pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo){
    char texto[128];
    pilha_t *pilha;
    aeroporto_st *dado;

    /* Variáveis locais, conforme struct aeroporto */
    int indice;
    char sigla[4];
    char cidade[64];
    char estado [64];



    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    pilha = cria_pilha();

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */

   while (fscanf(fp, "%d,%4[^,],%128[^,],%128[^\n]", &indice, sigla, cidade, estado) == 4){

        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(indice, sigla, cidade, estado);
        push(dado,pilha);


     }
    fclose(fp);
    return pilha;
}



void liberar_dados(pilha_t *pilha){



}


