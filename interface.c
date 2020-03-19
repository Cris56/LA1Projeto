#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "logic.h"
#include "interface.h"

void mostrar_tabuleiro(ESTADO *e) { //Para imprimir o tabuleiro
    int n = 8;
    for(int i = 0; i < 8; i++) {
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
    char col[2], lin[2], cmd[10];
    int n = 0;
    printf("# [%d] (%d) PL%d > ", obter_num_comandos(e), obter_numero_jogadas(e), obter_jogador_atual(e));
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    else {
        sscanf(linha, "%s", cmd);
        if (!strcmp(cmd, "Q")) exit(0);
        if (!strcmp(cmd, "gr")) gravar(e);
        if (!strcmp(cmd, "ler")) ler();
    }
    mais_comandos(e);
    return 1;
}

void gravar(ESTADO *e) {
    FILE *fp;
    fp = fopen("C:\\Users\\user\\CLionProjects\\ProjetoLA1\\FicheirosTeste\\teste.txt", "w");
    int n = 8;
    for(int i = 0; i < 8; i++) {
        fprintf(fp,"%d ", n);
        n -= 1;
        for (int j = 0; j < 8; j++) {
            fprintf(fp,"%c", obter_casa(e, coordenada(j, i)));
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"  abcdefgh\n");
    fclose(fp);
}

void ler() {
    FILE *fp;
    fp = fopen("C:\\Users\\user\\CLionProjects\\ProjetoLA1\\FicheirosTeste\\teste.txt", "r");
}
