#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "quick.h"
#include "../../utils/swap/swap.h"

int partition(Card cards[], int low, int high) {
    Card pivot = cards[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (cards[j].colorId < pivot.colorId || (cards[j].colorId == pivot.colorId && cards[j].valueId < pivot.valueId)) {
            i++;
            swap(&cards[i], &cards[j]);
        }
    }

    swap(&cards[i + 1], &cards[high]);
    return i + 1;
}

void quickSort(Card cards[], int low, int high) {
    if (low < high) {
        int pi = partition(cards, low, high);

        quickSort(cards, low, pi - 1);
        quickSort(cards, pi + 1, high);
    }
}

SortingPayload quickSortWrapper(Card cards[], int n) {
    int moves = 0;
    int comparisons = 0;
    double cpu_time_used;
    clock_t start, end;
    start = clock();

    quickSort(cards, 0, n - 1);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}
