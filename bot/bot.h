/**
 * @file bot.h
 * Definição das funções principais do bot
 */

#ifndef __BOT_H__
#define __BOT_H__
#define BUF_SIZE 1024

/**
 * \brief Efetua os comandos necessários.
 * @param e Apontador para o estado
 * @param ler Nome do ficheiro a ler
 * @param gravar Nome a dar ao ficheiro a gravar
 */
void bot(ESTADO *e, char *ler, char *gravar);

/**
 * \brief Lê um ficheiro.
 * @param e Apontador para o estado
 * @param nome Nome do ficheiro a ler
 */
void lerf(ESTADO *e, char *nome);

/**
 * \brief Faz uma jogada automática (escolha aleatória).
 * @param e Apontador para o estado
 */
void jog(ESTADO *e);

/**
 * \brief Grava um ficheiro com o tabuleiro atual.
 * @param e Apontador para o estado
 * @param nome Nome a dar ao ficheiro a gravar
 */
void gravarf(ESTADO *e, char *nome);

#endif