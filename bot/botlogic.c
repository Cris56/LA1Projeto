#include <stdlib.h>
#include "botdata.h"
#include "botlogic.h"

void jog_jogadas(ESTADO *e, COORDENADA c) {
    int i = 0;
    int j = obter_jogador_atual(e);
    int jog = obter_numero_jogadas(e) + 1;
    if (j == 1) i = 2;
    if (j == 2) i = 1;
    mudar_jogador_atual(e, i);
    alterar_jogada(e, c, j, jog);
}

int verifica_jogada(ESTADO *e, COORDENADA c) {
    int ret;
    COORDENADA ultima = obter_ultima_jogada(e);
    int col1, lin1, col2, lin2;
    col1 = ultima.coluna;
    lin1 = ultima.linha;
    col2 = c.coluna;
    lin2 = c.linha;
    int difcol = (col1 - col2);
    int diflin = (lin1 - lin2);
    if ((difcol * difcol) == 0 && (diflin * diflin) == 0) ret = 0;
    if (((difcol) * (difcol) <= 1) && ((diflin) * (diflin) <= 1) && obter_casa(e, c) != PRETA && obter_casa(e, c) != BRANCA)
        ret = 1;
    else ret = 0;
    return ret;
}



COORDENADA chars_para_coord(char c, char l) {
    COORDENADA coord = {c - 'a', '8' - l};
    return coord;
}

COORDENADA *duplicar_coordenada(COORDENADA c) {
    COORDENADA *coord = malloc(sizeof(COORDENADA));
    coord->linha = c.linha;
    coord->coluna = c.coluna;
    return coord;
}