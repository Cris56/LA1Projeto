#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "interface.h"

int main() {
    srand(time(NULL));
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while(interpretador(e));
    return 0;
}
