#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "dados.h"
#include "no.h"

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


lista_enc_t *ler_dados_csv(char *nome_do_arquivo){
    char texto[128];

    /* Demais Variáveis */
    lista_enc_t *lista;
    aeroporto_st *dado;
    no_t *meu_no;

    /* Veriáveis locais, conforme struct aeroporto */
    int indice;
    char sigla[4];
    char cidade[64];
    char estado [64];

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    lista = criar_lista_enc();

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */


    while (fscanf(fp, "%d,%4[^,],%128[^,],%128[^\n]", &indice, sigla, cidade, estado) == 4)
    {
        //#ifdef DEBUG
        printf("%s\n",cidade);
        //#endif  // DEBUG

         //Cria um novo dado abstrato e armazena a sua referência/
         dado = criar_dado(indice, sigla, cidade, estado);
         meu_no = criar_no(dado);
         add_cauda(lista, meu_no);

    }

    return lista;
}




void liberar_dados(no_t *cabeca)
{
    no_t *temp;
    while (obter_proximo (cabeca)!= NULL)
    {
        free (obter_dado(cabeca));
        temp = obter_proximo(cabeca);
        free (cabeca);
        cabeca = temp;
    }
}


