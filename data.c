#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

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

int obter_jogador_atual(ESTADO *e) {
    int jog = e->jogador_atual;
    return jog;
}

void mudar_jogador_atual(ESTADO *e, int j) {
    e->jogador_atual = j;
}

int obter_numero_jogadas(ESTADO *e) {
    int n = e->num_jogadas;
    return n;
}

void mais_jogadas(ESTADO *e) {
    e->num_jogadas += 1;
}

CASA obter_casa(ESTADO *e, COORDENADA c) {
    CASA casa = e->tab[c.coluna][c.linha];
    return casa;
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

int obter_num_comandos(ESTADO *e) {
    int cmds = e->num_comandos;
    return cmds;
}

void mais_comandos(ESTADO *e) {
    e->num_comandos += 1;
}

COORDENADA obter_ultima_jogada(ESTADO *e){
    COORDENADA last = e->ultima_jogada;
    return last;
}

int fimdojogo(ESTADO *e, COORDENADA c){
    if(obter_casa(e,c) == UM || obter_casa(e,c) == DOIS || vizinhas_cheias(e,c)){
        return 1;
    } else return 0;
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
