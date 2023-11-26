#include <stdlib.h>
#include <stdio.h>
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
void printArrayFile(Card arr[], int size, FILE* output);

void createSortingPayload( SortingPayload *payload, int size, int moves, int comparisions, double time, Card cards[]);

void showSortingPayload( SortingPayload *payload );

void showSortingPayloadFile( SortingPayload *payload, FILE* output);
#endif // SORTING_PAYLOAD_H