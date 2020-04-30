#include <stdio.h>
#include <stdlib.h>
#include "botdata.h"
#include "botlogic.h"
#include "listas.h"
#include "bot.h"

void bot(ESTADO *e, char *ler, char *gravar) {
    lerf(e, ler);
    jog(e);
    gravarf(e, gravar);
}

void lerf(ESTADO *e, char *nome) {
    FILE *f = fopen(nome, "r");
    char buffer[BUF_SIZE];
    int l = 0;
    while (fgets(buffer, BUF_SIZE, f) != NULL) {
        if (l == 8) break;
        for (int c = 0; c < 8; c++) {
            mudar_casa(e, coordenada(c, l), buffer[c]);
        }
        l++;
    }
    while (fgets(buffer, BUF_SIZE, f) != NULL) {
        int num_jog;
        char c1, c2, l1, l2;
        int num_tokens = sscanf(buffer, "%d: %c%c %c%c", &num_jog, &c1, &l1, &c2, &l2);
        alterar_num_jogadas(e, num_jog);
        COORDENADA p1 = chars_para_coord(c1, l1);
        COORDENADA p2 = chars_para_coord(c2, l2);
        if (num_tokens == 5) {
            alterar_jogada(e, p1, 1, num_jog);
            alterar_jogada(e, p2, 2, num_jog);
            mudar_ultima_jogada(e, p2);
            mudar_jogador_atual(e, 1);
        } else if (num_tokens == 3) {
            alterar_jogada(e, p1, 1, num_jog);
            mudar_ultima_jogada(e, p1);
            mudar_jogador_atual(e, 2);
        }
    }
    fclose(f);
}


void jog(ESTADO *e) {
    COORDENADA *jog = malloc(sizeof(COORDENADA));
    COORDENADA jogada, ult = obter_ultima_jogada(e);
    int ultcol = ult.coluna, ultlin = ult.linha, j = obter_jogador_atual(e), n = 0;
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
}


void gravarf(ESTADO *e, char *nome) {
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