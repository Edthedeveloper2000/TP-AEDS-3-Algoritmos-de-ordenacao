#include "../../types/SortingPayload/sortingPayload.h"

#ifndef QUICK_H
#define QUICK_H

SortingPayload quickSortWrapper(Card cards[], int n);
void quickSort(Card cards[], int low, int high, int *moves, int *comparisions);
int partition(Card cards[], int low, int high, int *moves, int *comparisions);

#endif //QUICK_H