#include <stdlib.h>
#include "data.h"
#include "logic.h"
#include "listas.h"

int jogar(ESTADO *e, COORDENADA c) {
    int p = verifica_jogada(e, c);
    if (p == 1) {
        mudar_casa(e, c,BRANCA);
        mudar_casa(e, obter_ultima_jogada(e),PRETA);
        mudar_ultima_jogada(e, c);
        jog_jogadas(e, c);
        if (obter_jogador_atual(e) == 1) mais_jogadas(e);
        return 1;
    }
    return 0;
}



void pos(ESTADO *e, int a) {
    int n = obter_numero_jogadas(e);
    COORDENADA ult;
    if (a == 0) ult = chars_para_coord('e', '5');
    else ult = obter_mov_jogador(e, a, 2);
    if (a < n) {
        for (int i = a + 1; i < n + 1; i++) {
            COORDENADA coord1 = obter_mov_jogador(e, i, 1);
            COORDENADA coord2 = obter_mov_jogador(e, i, 2);
            mudar_casa(e, coord1, VAZIO);
            mudar_casa(e, coord2, VAZIO);
        }
        if (obter_jogador_atual(e) == 2) mudar_casa(e, obter_ultima_jogada(e), VAZIO);
    } else if (a > n) {
        for (int j = n; j <= a; j++) {
            COORDENADA coord1 = obter_mov_jogador(e, j, 1);
            COORDENADA coord2 = obter_mov_jogador(e, j, 2);
            mudar_casa(e, coord1, PRETA);
            mudar_casa(e, coord2, PRETA);
        }
        if (obter_jogador_atual(e) == 2) mudar_casa(e, obter_ultima_jogada(e), PRETA);
    }
    mudar_casa(e, ult, BRANCA);
    mudar_ultima_jogada(e, ult);
    mudar_jogador_atual(e, 1);
    alterar_num_jogadas(e, a);
}



int jog(ESTADO *e) {
    COORDENADA *jog = malloc(sizeof(COORDENADA));
    COORDENADA jogada = {0, 0}, ult = obter_ultima_jogada(e);
    int ultcol = ult.coluna, ultlin = ult.linha, j = obter_jogador_atual(e), n = 0, ret = 1;
    LISTA L = criar_lista();
    for (int c = ultcol - 1; c < ultcol + 2; c++)
        for (int l = ultlin - 1; l < ultlin + 2; l++) {
            COORDENADA coord = coordenada(c, l);
            if (verifica_jogada(e, coord) == 1 && c >= 0 && c <= 7 && l >= 0 && l <= 7) {
                L = insere_cabeca(L, duplicar_coordenada(coord));
                n++;
            }
        }
    if (!lista_esta_vazia(L)) {
        int r = rand()%n + 1;
        for (int s = 0; !lista_esta_vazia(L) && s < r; s++) {
            jog = devolve_cabeca(L);
            L = remove_cabeca(L);
        }
        jogada = *jog;
        mudar_casa(e, jogada,BRANCA);
        mudar_casa(e, ult,PRETA);
        mudar_ultima_jogada(e, jogada);
        jog_jogadas(e, jogada);
        if (j == 1) mais_jogadas(e);
    }
    if (fimdojogo(e, jogada)) ret = 10;
    return ret;
}

int jog2(ESTADO *e) {
    COORDENADA *jog = malloc(sizeof(COORDENADA));
    COORDENADA jogada = {0, 0}, ult = obter_ultima_jogada(e), maisprox;
    int ultcol = ult.coluna, ultlin = ult.linha, j = obter_jogador_atual(e), n = 0, ret = 1;
    LISTA L = criar_lista();
    for (int c = ultcol - 1; c <= ultcol + 1; c++)
        for (int l = ultlin - 1; l <= ultlin + 1; l++) {
            COORDENADA coord = coordenada(c, l);
            if (c >= 0 && c <= 7 && l >= 0 && l <= 7 && verifica_jogada(e, coord)) {
                L = insere_cabeca(L, duplicar_coordenada(coord));
                n++;
            }
        }
    if (!lista_esta_vazia(L)) {
        maisprox = *(COORDENADA *)devolve_cabeca(L);
        for (int s = 0; !lista_esta_vazia(L) && s < n; s++) {
            jog = devolve_cabeca(L);
            if (maisproximo(j, *jog, maisprox)) maisprox = *jog;
            L = remove_cabeca(L);
        }
        jogada = maisprox;
        mudar_casa(e, jogada,BRANCA);
        mudar_casa(e, ult,PRETA);
        mudar_ultima_jogada(e, jogada);
        jog_jogadas(e, jogada);
        if (j == 1) mais_jogadas(e);
    }
    if (fimdojogo(e, jogada)) ret = 10;
    return ret;
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

void jog_jogadas(ESTADO *e, COORDENADA c) {
    int i = 0;
    int j = obter_jogador_atual(e);
    int jog = obter_numero_jogadas(e) + 1;
    if (j == 1) i = 2;
    if (j == 2) i = 1;
    mudar_jogador_atual(e, i);
    alterar_jogada(e, c, j, jog);
}



int fimdojogo(ESTADO *e, COORDENADA c) {
    if (casa_final(c) == 1 || casa_final(c) == 2 || vizinhas_cheias(e, c)) {
        return 1;
    }
    else return 0;
}

int casa_final(COORDENADA c) {
    int ret = 0;
    if (c.coluna == 0 && c.linha == 7) ret = 1;
    else if (c.coluna == 7 && c.linha == 0) ret = 2;
    return ret;
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

int vencedor(ESTADO *e, COORDENADA c) {
    int v, j = obter_jogador_atual(e), f = casa_final(c);
    if (j == 1) j = 2; else j = 1;
    if (f == 1) v = 1; else if (f == 2) v = 2; else v = j;
    return v;
}



int maisproximo(int j, COORDENADA jogada, COORDENADA atual) {
    int ret = 0;
    COORDENADA final1 = {0, 7}, final2 = {7, 0};
    switch (j) {
        case 1:
            if ((distancia(final1, atual) > distancia(final1, jogada) || casa_final(jogada) == 1)) ret = 1;
            break;
        case 2:
            if ((distancia(final2, atual) > distancia(final2, jogada) || casa_final(jogada) == 2)) ret = 1;
            break;
        default: ret = 0;
    }
    return ret;
}

int distancia(COORDENADA a, COORDENADA b) {
    int acol = a.coluna, alin = a.linha;
    int bcol = b.coluna, blin = b.linha;
    int dist = abs((bcol - acol)) + abs((blin - alin));
    return dist;
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
