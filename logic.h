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

#endif
