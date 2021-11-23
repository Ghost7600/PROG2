/* Autor: Kenner Marqueti Couto *
 * Código para leitura de um arquivo .csv e armazenamento de dados em estruturas apontadas por vetor de ponteiros
 * Data 29/10/2021
 */


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeroportos.h"





int main()
{


    int i;
    int qlinhas;
    aeroporto_st **paeroportos;

    paeroportos = ler_dados_csv("aeroportos.csv", &qlinhas);
    #ifdef DEBUG
    printf("%d \n" ,qlinhas);
    #endif
    /* Imprima os dados:*/
    for (i=0; i < qlinhas; i++)
    {
        printf( "%d ,%s ,%s ,%s \n", obter_indice(paeroportos[i]),obter_sigla(paeroportos[i]),obter_cidade(paeroportos[i]),obter_estado(paeroportos[i]));
    }

    liberar_dados(paeroportos,qlinhas);

    return 0;
}
