#ifndef DADO_H_INCLUDED

#include "fila.h"

typedef struct dados dado_t;

dado_t * criar_dado (int amostra, float temperatura, char * timestamp);

fila_t *ler_dados_csv_fila(char *nome_do_arquivo);

void liberar_dados(fila_t *fila);

void imprimir_fila(fila_t *fila);

#endif
