#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"
#include "dados.h"

struct dados {
    int amostra;
    float temperatura;
    char tempo[64];
};

dado_t * criar_dado (int amostra, float temperatura, char * timestamp){

    dado_t * dado = malloc(sizeof(dado_t));

    dado->amostra = amostra;

    dado->temperatura = temperatura;

    strcpy(dado->tempo, timestamp);

    return dado;
}

fila_t *ler_dados_csv_fila(char *nome_do_arquivo){

	char texto[64];

    int amostra;

    float temperatura;

    fila_t *fila;

    dado_t *dado;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    fila = cria_fila();

    fgets(texto,64, fp);

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        //printf("Lido %d, %f, %s\n", amostra, temperatura, texto);

        dado = criar_dado(amostra, temperatura, texto);
        enqueue(dado,fila);
        printf("Lido %d, %f, %s\n", amostra, temperatura, texto);
    }

    return fila;
}



void liberar_dados(fila_t *fila){
	libera_fila(fila);
}

void imprimir_fila(fila_t *fila){
	lista_enc_t *lista;
	no_t *cabeca;
	dado_t *dados;

	while (!fila_vazia(fila)){
		lista = retornar_lista(fila);
		cabeca = obter_cabeca(lista);
		dados = obter_dado(cabeca);


		printf("%d %f %s\n", dados->amostra, dados->temperatura, dados->tempo);

		dequeue(fila);
	}
}
