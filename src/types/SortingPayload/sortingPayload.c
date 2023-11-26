#include <stdio.h>
#include "sortingPayload.h"

void printArray(Card arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("[%d]: %s %s \n", i + 1, arr[i].color, arr[i].value);
    }
}
void printArrayFile(Card arr[], int size, FILE* output) {
    int i;
    for (i = 0; i < size; i++) {
        fprintf(output, "[%d]: %s %s \n", i + 1, arr[i].color, arr[i].value);
    }
}


void createSortingPayload( SortingPayload *payload, int size, int moves, int comparisions, double time, Card cards[])  {
    payload->comparisons = comparisions;
    payload->moves = moves;
    payload->size = size;
    payload->sortedCards = cards;
    payload->time = time;
}

void showSortingPayload( SortingPayload *payload) {
    printf("Mão de cartas:\n");
    printArray(payload->sortedCards, payload->size);
    printf("Comparações: %d, ", payload->comparisons);
    printf("Movimentos: %d, ", payload->moves);
    printf("Tempo: %f segundos\n", payload->time);
    printf("-------------------------\n");
}

void showSortingPayloadFile( SortingPayload *payload, FILE* output) {
    fprintf(output, "Mão de cartas:\n");
    printArrayFile(payload->sortedCards, payload->size, output);
    fprintf(output, "Comparações: %d, ", payload->comparisons);
    fprintf(output, "Movimentos: %d, ", payload->moves);
    fprintf(output, "Tempo: %f segundos\n", payload->time);
    fprintf(output, "-------------------------\n");
}