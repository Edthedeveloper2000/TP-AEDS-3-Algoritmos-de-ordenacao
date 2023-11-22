#include "../Card/card.h"

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