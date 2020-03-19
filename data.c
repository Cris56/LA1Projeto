#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

ESTADO *inicializar_estado() { //Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            mudar_casa(e, coordenada(j, i), VAZIO);
        }
    mudar_casa(e, coordenada(0, 7), UM);
    mudar_casa(e, coordenada(7, 0), DOIS);
    mudar_casa(e, coordenada(4, 3), BRANCA);
    return e;
}

int obter_jogador_atual(ESTADO *estado) { //Esta função permite obter o número do jogador atual

}

int obter_numero_de_jogadas(ESTADO *estado) { //Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores)


}

CASA obter_casa(ESTADO *e, COORDENADA c) { //Esta função permite obter o estado atual da casa
    CASA casa = e->tab[c.coluna][c.linha];
    return casa;
}

void mudar_casa(ESTADO *e, COORDENADA c, CASA A) { //Muda o estado da casa
    e->tab[c.coluna][c.linha] = A;
}

COORDENADA coordenada(int j, int i) { //Transforma dois inteiros i e j numa coordenada
    COORDENADA c;
    c.coluna = j;
    c.linha = i;
    return c;
}
