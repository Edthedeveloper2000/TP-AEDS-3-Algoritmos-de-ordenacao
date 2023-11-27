#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "insert.h"

SortingPayload insertSort(Card cards[], int n) {
    int i, j;
    int moves = 0;
    int comparisons = 0;
    double cpu_time_used;
    clock_t start, end;
    start = clock();

    for (i = 1; i < n; i++) {
        Card aux = cards[i];
        j = i - 1;

        while (j >= 0 && (cards[j].colorId > aux.colorId || (cards[j].colorId == aux.colorId && cards[j].valueId > aux.valueId))) {
            cards[j + 1] = cards[j];
            j = j - 1;
            moves++;
            comparisons += 4; 
        }

        cards[j + 1] = aux;
        moves++;
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}