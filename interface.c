#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"
#include "interface.h"


void mostrar_tabuleiro(ESTADO *e) { //Para imprimir o tabuleiro

}

int interpretador(ESTADO *e) { //[A completar]
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}
//1. Ler uma linha (usando fgets)
//2. Separar a linha por espaços (por exemplo utilizando sscanf ou strtok)
//3. Conforme o comando a executar, chamar a função correspondente do interface ou da lógica do programa e depois do interface.
