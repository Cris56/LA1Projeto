#include <stdlib.h>
#include "botdata.h"

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->num_comandos = 1;
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->ultima_jogada = coordenada(4, 3);
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            mudar_casa(e, coordenada(j, i), VAZIO);
        }
    mudar_casa(e, coordenada(0, 7), UM);
    mudar_casa(e, coordenada(7, 0), DOIS);
    mudar_casa(e, coordenada(4, 3), BRANCA);
    return e;
}

void mudar_casa(ESTADO *e, COORDENADA c, CASA A) {
    e->tab[c.coluna][c.linha] = A;
}

COORDENADA coordenada(int j, int i) {
    COORDENADA c;
    c.coluna = j;
    c.linha = i;
    return c;
}

void alterar_jogada(ESTADO *e, COORDENADA c, int j, int jog) {
    if (j == 1) e->jogadas[jog - 1].jogador1 = c;
    if (j == 2) e->jogadas[jog - 1].jogador2 = c;
}

void alterar_num_jogadas(ESTADO *e, int j) {
    e->num_jogadas = j;
}

COORDENADA chars_para_coord(char c, char l) {
    COORDENADA coord = {c - 'a', '8' - l};
    return coord;
}

void mudar_jogador_atual(ESTADO *e, int j) {
    e->jogador_atual = j;
}

void mudar_ultima_jogada(ESTADO *e, COORDENADA c) {
    e->ultima_jogada = c;
}

COORDENADA obter_mov_jogador(ESTADO *e, int jog, int j) {
    COORDENADA c = {0, 0};
    if (j == 1) c = e->jogadas[jog - 1].jogador1;
    if (j == 2) c = e->jogadas[jog - 1].jogador2;
    return c;
}

COORDENADA obter_ultima_jogada(ESTADO *e){
    COORDENADA last = e->ultima_jogada;
    return last;
}

int obter_numero_jogadas(ESTADO *e) {
    int n = e->num_jogadas;
    return n;
}

int obter_jogador_atual(ESTADO *e) {
    int jog = e->jogador_atual;
    return jog;
}
CASA obter_casa(ESTADO *e, COORDENADA c) {
    CASA casa = e->tab[c.coluna][c.linha];
    return casa;
}
