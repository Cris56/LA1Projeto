/**
 * @file listas.h
 * Módulo das listas do programa
 */

#ifndef __LISTAS_H___
#define BUF_SIZE 1024

/**
 * \brief Tipo de dados para as listas.
 */
typedef struct nodo {
    void *valor;
    struct nodo *proximo;
} NODO, *LISTA;

/**
 * \brief Cria uma lista vazia.
 * @return Lista criada
 */
LISTA criar_lista();

/**
 * \brief Insere um valor na cabeça da lista.
 * @param L Lista onde será inserida a cabeça
 * @param valor Valor a inserir na cabeça
 * @return O nodo head
 */
LISTA insere_cabeca(LISTA L, void *valor);

/**
 * \brief Devolve a cabeça da lista.
 * @param L Lista em questão
 * @return Apontador para a cabeça
 */
void *devolve_cabeca(LISTA L);

/**
 * \brief Devolve a cauda da lista.
 * @param L Lista em questão
 * @return A cauda da lista
 */
LISTA devolve_proximo(LISTA L);

/**
 * \brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda.
 * @param L Lista em questão
 * @return A cauda da lista
 */
LISTA remove_cabeca(LISTA L);

/**
 * \brief Devolve verdadeiro se a lista é vazia.
 * @param L Lista em questão
 * @return Verdadeiro (1) se a lista está vazia
 */
int lista_esta_vazia(LISTA L);

#endif
