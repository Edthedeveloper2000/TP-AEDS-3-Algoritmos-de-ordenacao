#include <time.h>
#include <stdio.h>
#include "../../types/SortingPayload/sortingPayload.h"

#ifndef BUBBLE_H
#define BUBBLE_H

/**
 * Realiza a ordenação de um array de cartas com bubblesort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
 * @return SortingPayload - entidade com as informações de tempo,
 * movimentações e comparações do sorting.
*/
SortingPayload bubbleSort(Card cards[], int n);

#endif // BUBBLE_H
