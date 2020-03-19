/**
 * @file interface.h
 * Definição das funções da parte da interface do programa
 */

#ifndef ___INTERFACE_H___
#define  ___INTERFACE_H___
#define BUF_SIZE 1024

/**
 * \brief Função que imprime o tabuleiro.
 * @param e Apontador para o estado
 */
void mostrar_tabuleiro(ESTADO *e);

/**
 * \brief Interpretador de comandos.
 *
 * A função deve:
 * 1. Ler uma linha (usando fgets)
 * 2. Separar a linha por espaços (por exemplo utilizando sscanf ou strtok)
 * 3. Conforme o comando a executar, chamar a função correspondente do interface ou da lógica do programa e depois do interface.
 * @param e Apontador para o estado
 * @return 1
 */
int interpretador(ESTADO *e);

#endif
