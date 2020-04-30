/**
 * @file data.h
 * Definição do estado e das funções que o manipulam
 */

#ifndef ___DATA_H___
#define  ___DATA_H___
#define BUF_SIZE 1024

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
    /** O número de comandos executados */
    int num_comandos;
} ESTADO;



/**
 * \brief Inicializa o valor do estado.
 * Implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
 * @returns O novo estado
 */
ESTADO *inicializar_estado();



/**
 * \brief Adiciona uma jogada ao número existente
 * @param e Apontador para o estado
 */
void mais_jogadas(ESTADO *e);

/**
 * \brief Adiciona um ao número total de comandos executados
 * @param e Apontador para o estado
 */
void mais_comandos(ESTADO *e);



/**
 * \brief Transforma dois valores i e j numa coordenada a utilizar.
 * @param j Valor da coluna
 * @param i Valor da linha
 * @return A coordenada resultante
 */
COORDENADA coordenada(int j, int i);



/**
 * \brief Obtém a casa indicada.
 * @param e Apontador para o estado
 * @param c A coordenada dada
 * @returns O valor da casa
 */
CASA obter_casa(ESTADO *e, COORDENADA c);

/**
 * \brief Obtém o jogador atual.
 * @param e Apontador para o estado
 * @return O número do jogador atual
 */
int obter_jogador_atual(ESTADO *e);

/**
 * \brief Permite obter quantas jogadas foram efetuadas.
 * (Cada jogada tem o movimento de dois jogadores)
 * @param e Apontador para o estado
 * @return Número de jogadas
 */
int obter_numero_jogadas(ESTADO *e);

/**
 * \brief Obtém o número total de comandos executados
 * @param e Apontador para o estado
 * @return Número de comandos
 */
int obter_num_comandos(ESTADO *e);

/**
 * \brief Obtém a última jogada.
 * @param e Apontador para o estado
 * @return A coordenada da última jogada
 */
COORDENADA obter_ultima_jogada(ESTADO *e);

/**
 * \brief Obtém o movimento feito por um jogador na jogada.
 * @param e Apontador para o estado
 * @param jog O número da jogada
 * @param j O número do jogador
 * @return A coordenada do movimento
 */
COORDENADA obter_mov_jogador(ESTADO *e, int jog, int j);



/**
 * \brief Muda o valor da cada indicada.
 * @param e Apontador para o estado
 * @param c A coordenada dada
 * @param A O novo valor para a casa
 */
void mudar_casa(ESTADO *e, COORDENADA c, CASA A);

/**
 * \brief Muda o número do jogador atual
 * @param e Apontador para o estado
 * @param j Número do jogador a alterar
 */
void mudar_jogador_atual(ESTADO *e, int j);

/**
 * \brief Muda a coordenada correspondente à última jogada.
 * @param e Apontador para o estado
 * @param c A coordenada que passa a ser a última jogada
 */
void mudar_ultima_jogada(ESTADO *e, COORDENADA c);



/**
 * \brief Altera qual a jogada feita por um jogador.
 * @param e Apontador para o estado
 * @param c A coordenada da jogada a alterar
 * @param j O número do jogador
 * @param i O número da jogada a alterar
 */
void alterar_jogada(ESTADO *e, COORDENADA c, int j, int i);

/**
 * \brief Altera o número de jogadas totais.
 * @param e Apontador para o estado
 * @param j O número que passa a ser o número de jogadas totais
 */
void alterar_num_jogadas(ESTADO *e, int j);

#endif
