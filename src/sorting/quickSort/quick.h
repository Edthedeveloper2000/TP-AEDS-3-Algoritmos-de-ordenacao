#include "../../types/SortingPayload/sortingPayload.h"

#ifndef QUICK_H
#define QUICK_H

SortingPayload quickSortWrapper(Card cards[], int n);
void quickSort(Card cards[], int low, int high);
int partition(Card cards[], int low, int high);

#endif //QUICK_H