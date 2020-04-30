/**
 * @file botlogic.h
 * Definição das funções da parte lógica do programa
 */

#ifndef ___BOTLOGIC_H___
#define  ___BOTLOGIC_H___
#define BUF_SIZE 1024

/**
 * \brief Verifica se a jogada indicada é válida.
 * @param e Apontador para o estado
 * @param c A coordenada da jogada pretendida
 * @return 1 se a jogada for possível, 0 se não for
 */
int verifica_jogada(ESTADO *e, COORDENADA c);

/**
 * \brief Altera o jogador atual e jogadas.
 * @param e Apontador para o estado
 * @param c A coordenada da jogada feita
 */
void jog_jogadas(ESTADO *e, COORDENADA c);



/**
 * \brief Transforma dois caracteres em coordenada válida.
 * @param c Caracter coluna
 * @param l Caracter linha
 */
COORDENADA chars_para_coord(char c, char l);

/**
 * \brief Duplica uma coordenada (devolve o apontador para a mesma e aloca memória).
 * @param c Coordenada a duplicar
 * @return Apontador para a coordenada
 */
COORDENADA *duplicar_coordenada(COORDENADA c);

#endif