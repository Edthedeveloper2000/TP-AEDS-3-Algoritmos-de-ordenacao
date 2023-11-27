#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "quick.h"
#include "../../utils/swap/swap.h"

int partition(Card cards[], int low, int high, int *moves, int *comparisons) {
    Card pivot = cards[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (cards[j].colorId < pivot.colorId) {
            i++;
            swap(&cards[i], &cards[j]);
            (*moves)++;
            (*comparisons)++;

        } else if  (cards[j].colorId == pivot.colorId && cards[j].valueId < pivot.valueId) {
            i++;
            swap(&cards[i], &cards[j]);
            *moves++;   
            (*comparisons)+=3;
        } else {
            (*comparisons)+=3;
        }
    }

    swap(&cards[i + 1], &cards[high]);
    return i + 1;
}

void quickSort(Card cards[], int low, int high, int *moves, int *comparisons) {
    if (low < high) {
        (*moves)++;
        int pi = partition(cards, low, high, moves, comparisons);

        quickSort(cards, low, pi - 1, moves, comparisons);
        quickSort(cards, pi + 1, high, moves, comparisons);
    }
}

SortingPayload quickSortWrapper(Card cards[], int n) {
    int moves = 0;
    int comparisons = 0;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;

    QueryPerformanceFrequency(&frequency);
    
    QueryPerformanceCounter(&start);

    quickSort(cards, 0, n - 1, &moves, &comparisons);

    QueryPerformanceCounter(&end);

    double cpu_time_used = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}
