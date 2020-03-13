#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"

int jogar(ESTADO *e, COORDENADA c) { //[A completar]
    printf("jogar %d %d\n", c.coluna, c.linha);
    e->tab[c.coluna][c.linha] = BRANCA;
    return 1;
}
//Esta função deverá receber o estado atual e uma coordenada e modificar o estado ao jogar na casa correta se a jogada for válida.
//A função devolve verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso não seja possível.
