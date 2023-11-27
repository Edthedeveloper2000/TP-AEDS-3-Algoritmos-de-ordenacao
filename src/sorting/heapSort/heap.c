#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "../../utils/swap/swap.h"

void heapify(Card cards[], int n, int i, int *comparisons, int *moves) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    (*comparisons)++;
    if (left < n && (cards[left].colorId > cards[largest].colorId || (cards[left].colorId == cards[largest].colorId && cards[left].valueId > cards[largest].valueId))) {
        largest = left;
    }

    (*comparisons)++;
    if (right < n && (cards[right].colorId > cards[largest].colorId || (cards[right].colorId == cards[largest].colorId && cards[right].valueId > cards[largest].valueId))) {
        largest = right;
    }

    if (largest != i) {
        (*comparisons)++;
        (*moves)++;
        swap(&cards[i], &cards[largest]);
        heapify(cards, n, largest, comparisons, moves);
    }
}

SortingPayload heapSort(Card cards[], int n) {
    int moves = 0;
    int comparisons = 0;
    double cpu_time_used;
    clock_t start, end;
    start = clock();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(cards, n, i, &comparisons, &moves);
    }

    for (int i = n - 1; i > 0; i--) {
         moves++;
        swap(&cards[0], &cards[i]);
        heapify(cards, i, 0, &comparisons, &moves);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}
