#include <time.h>
#include <stdio.h>
#include "../../types/SortingPayload/sortingPayload.h"

#ifndef INSERT_H
#define INSERT_H

/**
 * Realiza a ordenação de um array de cartas com insertSort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
 * @return SortingPayload - entidade com as informações de tempo,
 * movimentações e comparações do sorting.
*/
SortingPayload insertSort(Card cards[], int n);


#endif // INSERT_H
