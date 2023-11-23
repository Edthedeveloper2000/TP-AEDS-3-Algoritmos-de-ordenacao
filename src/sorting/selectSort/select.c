#include <time.h>
#include "select.h"

SortingPayload SelectSort(Card* cards, int n){
    int i, j, min;
    Card aux;
    int moves = 0;
    int comparisons = 0;
    double cpu_time_used;
    clock_t start, end;
    start = clock();
    for (i = 0; i < n - 1; i ++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(cards[min].colorId > cards[j].colorId){
                min = j;
                comparisons++;
            } else if (cards[min].colorId == cards[j].colorId && cards[min].valueId > cards[j].valueId) {
                min = j;
                comparisons+=2;
            } else {
                comparisons+=2;
            }
        }
        aux = cards[min];
        cards[min] = cards[i];
        cards[i] = aux;
        moves++;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    SortingPayload payload;
    createSortingPayload(&payload, n, moves, comparisons, cpu_time_used, cards);
    return payload;
}
