#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "shell.h"

SortingPayload shellSort(Card cards[], int n) {
    int i, j, h;
    int moves = 0;
    int comparisons = 0;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;

    QueryPerformanceFrequency(&frequency);
    
    QueryPerformanceCounter(&start);

    for (h = n / 2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            Card aux = cards[i];
            j = i;

            while (j >= h && (cards[j - h].colorId > aux.colorId ||
                (cards[j - h].colorId == aux.colorId && cards[j - h].valueId > aux.valueId))) {
                cards[j] = cards[j - h];
                j -= h;
                moves++;
                comparisons += 3;
            }

            cards[j] = aux;
            moves++;
        }
    }

    QueryPerformanceCounter(&end);

    double cpu_time_used = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}