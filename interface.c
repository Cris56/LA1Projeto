#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"
#include "interface.h"

void mostrar_tabuleiro(ESTADO *e) {
    int n = 1;
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", n);
        n += 1;
        for (int j = 0; j < 8; j++) {
            printf("%c", obter_casa(e, coordenada(j, i)));
        }
        printf("\n");
    }
    printf("  abcdefgh\n\n");
}

int interpretador(ESTADO *e) { //[A completar]
    char linha[BUF_SIZE];
    char col[2], lin[2], cmd[50], arg[100], q[1];
    printf("# [%d] (%d) PL%d > ", obter_num_comandos(e), obter_numero_jogadas(e), obter_jogador_atual(e));
    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
        if (fimdojogo(e, coord)) {
            vencedor(e, coord);
            exit(0);
        }
    }
    else {
        if (sscanf(linha, "%s", q) && (!strcmp(q, "Q"))) exit(0);
        if (sscanf(linha, "%s %s", cmd, arg) == 2) {
            if (!strcmp(cmd, "gr")) gravar(e, arg);
            if (!strcmp(cmd, "ler")) ler(arg);
        }
    }
    mais_comandos(e);
    return 1;
}

void gravar(ESTADO *e, char *nome) {
    FILE *fp;
    fp = fopen(nome, "w");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fprintf(fp,"%c", obter_casa(e, coordenada(j, i)));
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"\n");
    fclose(fp);
}

void ler(char *nome) {
    FILE *fp;
    fp = fopen(nome, "r");
}

void vencedor(ESTADO *e, COORDENADA c) {
    int v = 0;
    int j = obter_jogador_atual(e);
    int f = casa_final(c);
    if (f == 1) v = 1;
    else if (f == 2) v = 2;
    else v = j;
    printf("O vencedor e' o jogador %d! Parabens.\n", v);
}
