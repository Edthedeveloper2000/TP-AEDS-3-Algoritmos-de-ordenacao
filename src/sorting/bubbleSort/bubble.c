#include <stdio.h>
#include <windows.h>
#include "bubble.h"
#include "../../utils/swap/swap.h"

SortingPayload bubbleSort(Card cards[], int n) {
    int i, j;
    int moves = 0;
    int comparisons = 0;
    
    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;

    QueryPerformanceFrequency(&frequency);
    
    QueryPerformanceCounter(&start);

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (cards[j].colorId > cards[j+1].colorId) {
                swap(&cards[j], &cards[j+1]);
                moves++;
                comparisons++;
            } else if (cards[j].colorId == cards[j+1].colorId && cards[j].valueId > cards[j+1].valueId) {
                swap(&cards[j], &cards[j+1]);
                moves++;
                comparisons+=3;
            } else {
                comparisons+=3;
            }
        }
    }

    QueryPerformanceCounter(&end);

    double cpu_time_used = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}
