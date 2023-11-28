#include "../../types/SortingPayload/sortingPayload.h"

#ifndef QUICK_H
#define QUICK_H

/**
 * Realiza a ordenação de um array de cartas com quick sort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
*/
SortingPayload quickSortWrapper(Card cards[], int n);

/**
 * Realiza a ordenação de um array de cartas com quick sort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
*/
void quickSort(Card cards[], int low, int high, int *moves, int *comparisions);

/**
 * Gera uma particão dentro dos limites especificados para o quicksort
 * @param cards - array a ser ordenado
 * @param low - limite inferior
 * @param high - limite superior
 * @param moves- ponteiro que guarda a quantidade de movimentos
 * @param comparisions - ponteiro que guarda a quantidade de comparações
*/
int partition(Card cards[], int low, int high, int *moves, int *comparisions);

#endif //QUICK_H