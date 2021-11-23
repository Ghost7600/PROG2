#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"
#include "dados.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1

struct pilhas {
	lista_enc_t *lista;
};


//cria uma pilha generica
pilha_t * cria_pilha (void)
{
    pilha_t *p = malloc(sizeof(pilha_t));
    p->lista = criar_lista_enc();
    return p;




}



//adiciona elemento
void push(void* dado, pilha_t *pilha)
{
	no_t *no = criar_no(dado);
	add_cabeca(pilha->lista, no);



}

//retira elemento do topo
void *pop(pilha_t *pilha)
{
    no_t *no = remover_cabeca(pilha->lista);
    void *dado = obter_dado(no);
    free(no);
    return dado;


}


void libera_pilha(pilha_t* pilha)
{
    lista_enc_t *lista = pilha->lista;     //ver se funciona
    printf("%p --- lista\n",lista);

    no_t *no = obter_cabeca(lista);
    printf("%p --- cabeca\n",no);
    //aeroporto_st *dado = obter_dado(no);
    //free(dado);
    free(lista);
    free(pilha);


}

int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->lista);
}
