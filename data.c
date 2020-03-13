#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

ESTADO *inicializar_estado() { //Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) e->tab[j][i] = VAZIO;
    e->tab[0][7] = 49;
    e->tab[7][0] = 50;
    e->tab[4][3] = BRANCA;
    return e;
}

int obter_jogador_atual(ESTADO *estado) { //Esta função permite obter o número do jogador atual

}

int obter_numero_de_jogadas(ESTADO *estado) { //Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores)


}

CASA obter_estado_casa(ESTADO *e, COORDENADA c) { //Esta função permite obter o estado atual da casa
}
