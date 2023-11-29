#include <stdlib.h>
#include <stdio.h>
#include "../Card/card.h"

#ifndef SORTING_PAYLOAD_H
#define SORTING_PAYLOAD_H

typedef struct {
    int moves;
    int comparisons;
    Card *sortedCards;
    int size;
    double time;

} SortingPayload;

/**
 * Itera sobre uma lista de cartas e
 * mostra cor e valor de cada uma
 * @param cards[] - Lista de cartas a ser exibida no terminal
 * @param size - tamanho da lista
*/
void showCards(Card cards[], int size);

/**
 * Itera sobre uma lista de cartas e
 * mostra cor e valor de cada uma
 * @param cards[] - Lista de cartas a ser no arquivo de saida
 * @param size - tamanho da lista
 * @param output - arquivo de saida
*/
void showCardsFile(Card cards[], int size, FILE* output);

/**
 * Cria um SortingPayload com os dados fornecidos
 * @param payload - O ponteiro que guardará a instãncia do SortingPayload
 * @param size - Tamanho do vetor ordenado
 * @param moves - quantidade de movimentos
 * @param comparisions - Quantidade de comparações
 * @param time - tmepo gasto
 * @param cards[] - A lista ordenada.
*/
void createSortingPayload( SortingPayload *payload, int size, int moves, int comparisions, double time, Card cards[]);

/**
 * Exibe na saida padrão [ terminal ] os dados do payload,
 * como movimentos, comparações e tempo de execução
 * @param payload - o payload a ser visualizado
*/
void showSortingPayload( SortingPayload *payload );

/**
 * Exibe no arquivo de saida os dados do payload,
 * como movimentos, comparações e tempo de execução
 * @param payload - o payload a ser visualizado
 * @param output - o arquivo de saida
*/
void showSortingPayloadFile( SortingPayload *payload, FILE* output);
#endif // SORTING_PAYLOAD_H