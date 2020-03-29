#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"
#include "interface.h"

void mostrar_tabuleiro(ESTADO *e) {
    int n = 8;
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", n);
        n -= 1;
        for (int j = 0; j < 8; j++) {
            printf("%c", obter_casa(e, coordenada(j, i)));
        }
        printf("\n");
    }
    printf("  abcdefgh\n\n");
}

int interpretador(ESTADO *e) { //[A completar]
    char linha[BUF_SIZE];
    char col[2], lin[2], cmd[50], arg[100], q[1], m[4];
    printf("# [%d] (%d) PL%d > ", obter_num_comandos(e), obter_numero_jogadas(e), obter_jogador_atual(e));
    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = chars_para_coord(*col, *lin);//{*col - 'a', '8' - *lin}
        jogar(e, coord);
        mostrar_tabuleiro(e);
        if (fimdojogo(e, coord)) {
            vencedor(e, coord);
            exit(0);
        }
    }
    else {
        if (sscanf(linha, "%s", q) && (!strcmp(q, "Q"))) exit(0);
        if (sscanf(linha, "%s", m) && (!strcmp(m, "movs"))) movs(e);
        if (sscanf(linha, "%s %s", cmd, arg) == 2) {
            if (!strcmp(cmd, "gr")) gravar(e, arg);
            if (!strcmp(cmd, "ler")) ler(e, arg);
        }
        mostrar_tabuleiro(e);
    }
    mais_comandos(e);
    return 1;
}

void gravar(ESTADO *e, char *nome) {
    FILE *f;
    f = fopen(nome, "w");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fprintf(f ,"%c", obter_casa(e, coordenada(j, i)));
        }
        fprintf(f ,"\n");
    }
    fprintf(f,"\n");
    for (int i = 0; i <= obter_numero_jogadas(e); i++) {
        COORDENADA jog1 = obter_mov_jogador(e, i, 1);
        COORDENADA jog2 = obter_mov_jogador(e, i, 2);
        COORDENADA jog3 = obter_ultima_jogada(e);
        if (i == obter_numero_jogadas(e) && obter_jogador_atual(e) == 2) fprintf(f, "%d: %c%c\n", i + 1, jog3.coluna + 'a', '8' - jog3.linha);
        else {
            if (i == obter_numero_jogadas(e)) break;
            fprintf(f, "%d: %c%c %c%c\n", i + 1, jog1.coluna + 'a', '8' - jog1.linha, jog2.coluna + 'a', '8' - jog2.linha);
        }
    }
    fclose(f);
}

void ler(ESTADO *e, char *nome) { //[Ainda com problemas]
    FILE *f = fopen(nome, "r");
    char buffer[BUF_SIZE];
    int l = 0;
    while (fgets(buffer, BUF_SIZE, f) != NULL) {
        for (int c = 0; c < 8; c++) {
            mudar_casa(e, coordenada(c, l), buffer[c]);
        }
        l++;
    }
    fclose(f);
}

void movs(ESTADO *e) {
    printf("\n");
    for (int i = 0; i <= obter_numero_jogadas(e); i++) {
        COORDENADA jog1 = obter_mov_jogador(e, i, 1);
        COORDENADA jog2 = obter_mov_jogador(e, i, 2);
        COORDENADA jog3 = obter_ultima_jogada(e);
        if (i == obter_numero_jogadas(e) && obter_jogador_atual(e) == 2) printf("%d: %c%c\n", i + 1, jog3.coluna + 'a', '8' - jog3.linha);
        else {
            if (i == obter_numero_jogadas(e)) break;
            printf("%d: %c%c %c%c\n", i + 1, jog1.coluna + 'a', '8' - jog1.linha, jog2.coluna + 'a', '8' - jog2.linha);
        }
    }
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
