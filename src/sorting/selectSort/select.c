#include <time.h>
#include <windows.h>
#include "select.h"

SortingPayload SelectSort(Card* cards, int n){
    int i, j, min;
    Card aux;
    int moves = 0;
    int comparisons = 0;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;

    QueryPerformanceFrequency(&frequency);
    
    QueryPerformanceCounter(&start);

    for (i = 0; i < n - 1; i ++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(cards[min].colorId > cards[j].colorId){
                min = j;
                comparisons++;
            } else if (cards[min].colorId == cards[j].colorId && cards[min].valueId > cards[j].valueId) {
                min = j;
                comparisons+=3;
            } else {
                comparisons+=3;
            }
        }
        aux = cards[min];
        cards[min] = cards[i];
        cards[i] = aux;
        moves++;
    }

    QueryPerformanceCounter(&end);

    double cpu_time_used = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}
