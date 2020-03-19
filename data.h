/**
 * @file data.h
 * Definição do estado e das funções que o manipulam
 */

#ifndef ___DATA_H___
#define  ___DATA_H___
#define BUF_SIZE 1024

/**
 * \brief Tipo de dados para os erros
 */
typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO,
} ERROS;

/**
 * \brief Tipo de dados para a casa
 */
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

/**
 * \brief Tipo de dados para as coordenadas
 */
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
 * \brief Tipo de dados para a jogada
 */
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
 * \brief Tipo de dados para as jogadas
 */
typedef JOGADA JOGADAS[32];

/**
 * \brief Tipo de dados para o estado
 */
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** A coordenada da última jogada */
    COORDENADA ultima_jogada;
    /** As jogadas */
    JOGADAS jogadas;
    /** O número de jogadas (utilizado no prompt) */
    int num_jogadas;
    /** O número do jogador atual */
    int jogador_atual;
} ESTADO;

/**
 * \brief Inicializa o valor do estado.
 * Implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
 * @returns O novo estado
 */
ESTADO *inicializar_estado();

/**
 * \brief Obtém a casa indicada.
 * @param e Apontador para o estado
 * @param c A coordenada dada
 * @returns O valor da casa
 */
CASA obter_casa(ESTADO *e, COORDENADA c);

/**
 * \brief Muda o valor da cada indicada.
 * @param e Apontador para o estado
 * @param c A coordenada dada
 * @param A O novo valor para a casa
 */
void mudar_casa(ESTADO *e, COORDENADA c, CASA A);

/**
 * \brief Transforma dois valores i e j numa coordenada a utilizar.
 * @param j Valor da coluna
 * @param i Valor da linha
 * @return A coordenada resultante
 */
COORDENADA coordenada(int j, int i);

#endif

/* Por completar:
 * int obter_jogador_atual(ESTADO *estado);
 * int obter_numero_de_jogadas(ESTADO *estado);
 * [mudar jogador atual]
 * [mudar numero de jogadas]
 */
