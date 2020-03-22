/**
 * @file logic.h
 * Definição das funções da parte lógica do programa
 */

#ifndef ___LOGIC_H___
#define  ___LOGIC_H___
#define BUF_SIZE 1024

/**
 * \brief Função que efetua uma jogada.
 * Esta função deverá receber o estado atual e uma coordenada e modificar o estado ao jogar na casa correta se a jogada for válida.
 * A função devolve verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso não seja possível.
 * @param e Apontador para o estado
 * @param c A coordenada dada
 * @return Um valor que indique a possibilidade ou impossibilidade de jogar
 */
int jogar(ESTADO *e, COORDENADA c);

/**
 * \brief Verifica se a jogada indicada é válida.
 * @param e Apontador para o estado
 * @param c A coordenada da jogada pretendida
 * @return 1 se a jogada for possível, 0 se não for
 */
int verifica_jogada(ESTADO *e, COORDENADA c);

/**
 * \brief Verifica se o jogo deve acabar.
 * @param e Apontador para o estado
 * @param c Coordenada da última jogada
 * @return 1 se o jogo deverá acabar, 0 se deverá continuar
 */
int fimdojogo(ESTADO *e, COORDENADA c);

/**
 * \brief Verifica se as casas vizinhas estão cheias.
 * @param e Apontador para o estado
 * @param c Coordenada da última jogada
 * @return 0 se alguma está vazia, 1 se estão todas cheias
 */
int vizinhas_cheias(ESTADO *e, COORDENADA c);

/**
 * \brief Verifica se a casa é uma casa final.
 * @param e Apontador para o estado
 * @param c A coordenada da casa
 * @return 1 ou 2, consoante a casa final, ou 0 se não o é
 */
int casa_final(COORDENADA c);

#endif
