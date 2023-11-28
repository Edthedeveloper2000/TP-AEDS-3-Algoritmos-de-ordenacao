#include <time.h>
#include <stdio.h>
#include "../../types/SortingPayload/sortingPayload.h"

#ifndef HEAP_H
#define HEAP_H

/**
 * Realiza a ordenação de um array de cartas com heapsort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
*/
SortingPayload heapSort(Card cards[], int n);

/**
 * Cria a estrutura de heap necessária para o heapsort
 * @param cards - array a ser ordenado
 * @param n - tamanho de array
 * @param i - maior elemento atual
 * @param comparisions - ponteiro que guarda a quantidade de comparações
 * @param moves - ponteiro que guarda a quantidade de movimentos
*/
void heapify(Card cards[], int n, int i, int *comparisons, int *moves);


#endif // HEAP_H
