#include <time.h>
#include <stdio.h>
#include "../../types/SortingPayload/sortingPayload.h"

#ifndef BUBBLE_H
#define BUBBLE_H

void swap(Card *card_1, Card *card_2);
SortingPayload bubbleSort(Card cards[], int n);

#endif // BUBBLE_H
