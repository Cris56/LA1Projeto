#include <stdio.h>
#include "data.h"
#include "logic.h"
#include "interface.h"

int main() {
    ESTADO *e = inicializar_estado();
    while(interpretador(e));
    return 0;
}
