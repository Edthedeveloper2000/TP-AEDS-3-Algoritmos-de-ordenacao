#include "../Card/card.h"

#ifndef SORTING_PAYLOAD_H
#define SORTING_PAYLOAD_H

typedef struct {
    int moves;
    int comparisons;
    Card *sortedCards;
    int size;
    double time;

} SortingPayload;

void printArray(Card arr[], int size);

void createSortingPayload( SortingPayload *payload, int size, int moves, int comparisions, double time, Card cards[]);

void showSortingPayload( SortingPayload *payload );

#endif // SORTING_PAYLOAD_H