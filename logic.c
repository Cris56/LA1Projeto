#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"

int jogar(ESTADO *e, COORDENADA c) { //[A completar]
    int p = verifica_jogada(e, c);
    if(p == 1) {
        COORDENADA ult_jog = obter_ultima_jogada(e);
        mudar_casa(e, c,BRANCA);
        mudar_casa(e, ult_jog,PRETA);
        e->ultima_jogada = c;
        return 1;
    }
    return 0;
}

int verifica_jogada(ESTADO *e, COORDENADA c) {
    COORDENADA ultima = obter_ultima_jogada(e);
    int col1, lin1, col2, lin2;
    col1 = ultima.coluna;
    lin1 = ultima.linha;
    col2 = c.coluna;
    lin2 = c.linha;
    int difcol = (col1 - col2);
    int diflin = (lin1 - lin2);
    if ((difcol * difcol) == 0 && (diflin * diflin) == 0) return 0;
    if (((difcol) * (difcol) <= 1) && ((diflin) * (diflin) <= 1) && (obter_casa(e, c) == VAZIO))
        return 1;
    else return 0;
}
