#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"

int verifica_jogada(ESTADO *e, COORDENADA c){
    int col1, lin1, col2, lin2;

    col1 = e -> ultima_jogada.coluna;
    lin1 = e -> ultima_jogada.linha;
    col2 = c.coluna;
    lin2 = c.linha;

    if ((col1-col2)^2 <= 1 && (lin1-lin2)^2 <= 1 && obter_casa(e,c) == VAZIO){
        return 1;
    }
    else return 0;
}

int jogar(ESTADO *e, COORDENADA c) { //[A completar]
    printf("jogar %d %d\n", c.coluna, c.linha);
    
    if(verifica_jogada(e,c)){
        mudar_casa(e,c,BRANCA);
        return 1;
    }
    return 0;
}
//Esta função deverá receber o estado atual e uma coordenada e modificar o estado ao jogar na casa correta se a jogada for válida.
//A função devolve verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso não seja possível.
