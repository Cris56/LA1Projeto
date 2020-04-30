#include <stdio.h>
#include <string.h>
#include "botdata.h"
#include "bot.h"

int main() {
    ESTADO *e = inicializar_estado();
    char linha[BUF_SIZE], cmd[3], ler[BUF_SIZE], gr[BUF_SIZE];
    if (sscanf(linha, "%s %s %s", cmd, ler, gr) && !strcmp(cmd, "bot")) bot(e, ler, gr);
    return 0;
}
