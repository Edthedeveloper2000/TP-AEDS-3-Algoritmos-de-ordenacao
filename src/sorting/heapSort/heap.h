#include <time.h>
#include <stdio.h>
#include "../../types/SortingPayload/sortingPayload.h"

#ifndef HEAP_H
#define HEAP_H

SortingPayload heapSort(Card cards[], int n);
void heapify(Card cards[], int n, int i, int *comparisons, int *moves);


#endif // HEAP_H
