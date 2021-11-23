/* Módulo responsável por
 *
 * (...)
 */


/* Includes de sistema */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Includes do módulo */
#include "aeroportos.h"


/* Ativa depuração do módulo, comente para código final */



struct aeroporto
{
    int indice;
    char sigla[4];
    char cidade[128];
    char estado[128];
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


aeroporto_st * criar_aeroporto (int indice, char *sigla, char *cidade, char *estado)
{

    aeroporto_st * novo_aeroporto = malloc(sizeof(struct aeroporto));



    /* Novos dados são copiados para nova estrutura vinda do malloc */
    novo_aeroporto -> indice = indice;
    strncpy(novo_aeroporto -> sigla,sigla,4);
    strncpy(novo_aeroporto -> cidade,cidade,127);
    strncpy(novo_aeroporto -> estado,estado,127);



    return novo_aeroporto;
}





aeroporto_st **ler_dados_csv(char *nome_arquivo, int *qlinhas)
{


    char linha[128];
    char info[128];
    int indice;
    char sigla[4];
    char cidade[127];
    char estado[127];
    int cont;
    int i;

    FILE *fp;

    //Criando Vetor de ponteiros das structs

    aeroporto_st **vetorp;

    fp = fopen(nome_arquivo, "r");

    if (fp == NULL)
    {
        perror("função: ler_dados_csv");
        exit(EXIT_FAILURE);
    }

    /* Ignora primeira linha */
    fgets(info,128, fp);
#ifdef DEBUG
    puts(info);
#endif
    cont=0;

    /* Contar todas as linhas: use while e fgets() */
    while (fgets(linha, sizeof(linha), fp))
    {
        cont++;
    }
    *qlinhas = cont;

    rewind (fp);

    /* Ignora primeira linha */
    fgets(info,128, fp);


    // Alocando memória para o veotr de ponteiros

    vetorp = malloc(sizeof(aeroporto_st *) * cont);     //vetor de ponteiros contendo os ponteiros que apontam para cada struct

    if (vetorp == NULL)
    {
        perror("função: ler_dados_csv");
        exit(-1);
    }


    while (fscanf(fp, "%d,%4[^,],%127[^,],%127[^\n]", &indice, sigla, cidade, estado) == 4)
    {

#ifdef DEBUG
        printf("%s\n",cidade);
#endif  // DEBUG

        vetorp[i] = criar_aeroporto(indice,sigla,cidade,estado);
        i++;


    }

    fclose (fp);


    return vetorp;

}

void  liberar_dados(aeroporto_st **paeroportos,int qtd)
{
    int i;
    for (i=0; i<qtd; i++)
    {
        free(paeroportos[i]);
    }

    free(paeroportos);


}
