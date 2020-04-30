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
 * \brief Retorna o jogo à posição a seguir ao final da jogada indicada.
 * @param e Apontador para o estado
 * @param a O número da jogada
 */
void pos(ESTADO *e, int a);



/**
 * \brief Faz uma jogada pelo jogador (estratégia #1).
 * @param e Apontador para o estado
 * @return 1
 */
int jog(ESTADO *e);

/**
 * \brief Faz uma jogada pelo jogador (estratégia #2).
 * @param e Apontador para o estado
 * @return 1
 */
int jog2(ESTADO *e);



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
 * \brief Verifica se o jogo deve acabar.
 * @param e Apontador para o estado
 * @param c Coordenada da última jogada
 * @return 1 se o jogo deverá acabar, 0 se deverá continuar
 */
int fimdojogo(ESTADO *e, COORDENADA c);

/**
 * \brief Verifica se a casa é uma casa final.
 * @param e Apontador para o estado
 * @param c A coordenada da casa
 * @return 1 ou 2, consoante a casa final, ou 0 se não o é
 */
int casa_final(COORDENADA c);

/**
 * \brief Verifica se as casas vizinhas estão cheias.
 * @param e Apontador para o estado
 * @param c Coordenada da última jogada
 * @return 0 se alguma está vazia, 1 se estão todas cheias
 */
int vizinhas_cheias(ESTADO *e, COORDENADA c);

/**
 * \brief Determina e congratula o vencedor.
 * @param e Apontador para o estado
 * @param c A coordenada da jogada
 */
int vencedor(ESTADO *e, COORDENADA c);



/**
 * \brief Calcula se uma coordenada está mais próxima da casa final do que outra.
 * @param j Jogador atual
 * @param jogada Coordenada a ser verificada
 * @param atual Coordenada que será a jogada final
 * @return Verdadeiro se a que foi verificada está mais próxima
 */
int maisproximo(int j, COORDENADA jogada, COORDENADA atual);

/**
 * \brief Calcula a distância entre duas coordenadas (número de posições a percorrer).
 * @param a Coordenada a
 * @param b Coordenada b
 * @return A distância entre as duas coordenadas
 */
int distancia(COORDENADA a, COORDENADA b);



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
