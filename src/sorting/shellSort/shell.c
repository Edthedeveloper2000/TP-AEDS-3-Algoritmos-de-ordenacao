#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

SortingPayload shellSort(Card cards[], int n) {
    int i, j, h;
    int moves = 0;
    int comparisons = 0;
    double cpu_time_used;
    clock_t start, end;
    start = clock();

    for (h = n / 2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            Card aux = cards[i];
            j = i;

            while (j >= h && (cards[j - h].colorId > aux.colorId ||
                (cards[j - h].colorId == aux.colorId && cards[j - h].valueId > aux.valueId))) {
                cards[j] = cards[j - h];
                j -= h;
                moves++;
                comparisons += 2;
            }

            cards[j] = aux;
            moves++;
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}