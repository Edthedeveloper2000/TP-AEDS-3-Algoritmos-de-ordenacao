#include "../../types/SortingPayload/sortingPayload.h"

#ifndef SHELL_H
#define SHELL_H

/**
 * Realiza a ordenação de um array de cartas com shellSort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
 * @return SortingPayload - entidade com as informações de tempo,
 * movimentações e comparações do sorting.
*/
SortingPayload shellSort(Card cards[], int n);

#endif //SHELL_H