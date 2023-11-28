#include "../../types/SortingPayload/sortingPayload.h"
#ifndef SELECT_H
#define SELECT_H

/**
 * Realiza a ordenação de um array de cartas com selectsort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
 * @return SortingPayload - entidade com as informações de tempo,
 * movimentações e comparações do sorting.
*/
SortingPayload SelectSort(Card* cards, int n);

#endif // SELECT_H