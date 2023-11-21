#include <time.h>
#include <stdio.h>
#include "../../types/Card/card.h"

void swap(Card *card_1, Card *card_2) {
    Card temp = *card_1;
    *card_1 = *card_2;
    *card_2 = temp;
}

void printArray(Card arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("[%d]: %s %s \n", i + 1, arr[i].color, arr[i].value);
    }
}

void bubbleSort(Card cards[], int n) {
    int i, j;
    int moves = 0;
    int comparisons = 0;
    double cpu_time_used;
    clock_t start, end;
    start = clock();
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (cards[j].colorId > cards[j+1].colorId) {
                swap(&cards[j], &cards[j+1]);
                moves++;
                comparisons++;
            } else if (cards[j].colorId == cards[j+1].colorId && cards[j].valueId > cards[j+1].valueId) {
                swap(&cards[j], &cards[j+1]);
                moves++;
                comparisons+=2;
            } else {
                comparisons+=2;
            }
        }
    }

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort:\n");
    printf("Mão de cartas:\n");
    printArray(cards, n);
    printf("Comparaçõeções: %d, ", comparisons);
    printf("Movimentos: %d, ", moves);
    printf("Tempo: %f segundos\n", cpu_time_used);
}
