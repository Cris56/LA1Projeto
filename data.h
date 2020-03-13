typedef enum {
    VAZIO = 46,
    BRANCA = 42,
    PRETA = 35
} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

//tab armazena informação sobre o tabuleiro;
//ultima_jogada a coordenada da última jogada;
//jogadas armazena informação sobre as jogadas;
//num_jogadas indica quantas jogadas foram efetuadas;
//jogador_atual indica qual é o jogador a jogar;
