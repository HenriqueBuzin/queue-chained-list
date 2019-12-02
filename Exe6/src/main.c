#include <stdio.h>
#include "dados.h"
#include "fila.h"


int main(){
    fila_t *fila = ler_dados_csv_fila("camera_temp.csv");

    imprimir_fila(fila);

    liberar_dados(fila);

    return 0;
}
