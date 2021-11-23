/* Autor: Kenner Marqueti Couto *
 * Código para leitura de um arquivo .csv e armazenamento de dados em um vetor de estruturas
 *
 */


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados {
    int indice;
    char sigla[4];
    char cidade[128];
    char estado[128];

};



int main(){
    int i;
    int nlinhas = 0;
    char info[64];
    char linha[64];

    /* Ponteiro para alocação dinâmica dos dados */
    struct dados *ponteiro = NULL;

    /* Abrindo arquivo e testando se arquivo foi aberto */
    FILE *fp = fopen("aeroportos.csv","r");

    if (!fp){
        perror("main");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(info,64, fp);
    nlinhas=0;

    /* Contar todas as linhas: use while e fgets() */
    while (fgets(linha, sizeof(linha), fp)) {
            nlinhas++;
}



    /* Aloque memória: */
    ponteiro = malloc(sizeof(struct dados) * nlinhas);

    if (ponteiro == NULL){
    	perror("main");
    	exit(EXIT_FAILURE);
    }

    rewind(fp);     //volta ao início do arquivo e ignora 1a linha
    fgets(info,64, fp);

    /* Modifique aqui para colocar os dados no vetor
     * de estruturas alocado  dinamicamente *
     * ex: dados[i].posicao <- recebe o campo posição do arquivo;
     *
     * */
    i=0;
    while (fscanf(fp, "%d,%4[^,],%127[^,],%127[^\n]", &ponteiro[i].indice, ponteiro[i].sigla, ponteiro[i].cidade, ponteiro[i].estado) == 4){

       i++;

    }
    printf("gravou na estrutura \n");

    /* Imprima os dados:*/
    for (i=0; i < nlinhas; i++){
        printf("%d %s %s %s \n",ponteiro[i].indice, ponteiro[i].sigla, ponteiro[i].cidade, ponteiro[i].estado);
    }

    free(ponteiro);
    fclose(fp);
}
