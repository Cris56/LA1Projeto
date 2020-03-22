#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"

int jogar(ESTADO *e, COORDENADA c) {
    int p = verifica_jogada(e, c);
    if (p == 1) {
        mudar_casa(e, c,BRANCA);
        mudar_casa(e, obter_ultima_jogada(e),PRETA);
        mudar_ultima_jogada(e, c);
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
    if (((difcol) * (difcol) <= 1) && ((diflin) * (diflin) <= 1) && (obter_casa(e, c) != PRETA) && obter_casa(e, c) != BRANCA)
        return 1;
    else return 0;
}

int fimdojogo(ESTADO *e, COORDENADA c) {
    if (casa_final(c) == 1 || casa_final(c) == 2 || vizinhas_cheias(e, c)) {
        return 1;
    }
    else return 0;
}

int vizinhas_cheias(ESTADO *e, COORDENADA c) {
    int col = c.coluna, lin = c.linha;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++) {
            if (i != 0 && j != 0) {
                if (obter_casa(e, coordenada(col + j, lin + i)) == VAZIO) return 0;
            }
        }
    }
    return 1;
}

int casa_final(COORDENADA c) {
    if (c.coluna == 0 && c.linha == 7) return 1;
    else if (c.coluna == 7 && c.linha == 0) return 2;
    else return 0;
}
