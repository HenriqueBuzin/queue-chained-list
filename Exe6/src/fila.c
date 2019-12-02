#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"
#include "dados.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *dados;
};

//cria uma fila generica
fila_t * cria_fila (void)
{
	fila_t * fila = malloc(sizeof(fila_t));

	fila->dados = criar_lista_enc();

	return fila;
}

//adiciona elemento
void enqueue(void* dado, fila_t *fila)
{
	lista_enc_t *lista = retornar_lista(fila);
	no_t *no = criar_no(dado);
	add_cauda(lista, no);
}

//retira elemento do topo
void dequeue(fila_t *fila)
{
	lista_enc_t *lista = retornar_lista(fila);
	remover_cabeca(lista);
}


void libera_fila(fila_t* fila)
{
	lista_enc_t *lista = retornar_lista(fila);
	libera_lista(lista);
	free(fila);
}

int fila_vazia(fila_t *fila)
{
	lista_enc_t *lista = retornar_lista(fila);
	no_t *cabeca = obter_cabeca(lista);
	if(cabeca == NULL){
		return 1;
	} return 0;

}

lista_enc_t *retornar_lista(fila_t *fila){
	return fila->dados;
}
