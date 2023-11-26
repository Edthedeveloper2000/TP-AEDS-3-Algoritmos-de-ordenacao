#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "../utils/copyArray/copyArray.h"
#include "./bubbleSort/bubble.h"
#include "./selectSort/select.h"
#include "./InsertSort/insert.h"
#include "./shellSort/shell.h"
#include "./quickSort/quick.h"
#include "./heapSort/heap.h"

void sort(Card cards[]){
    printf("-------------------------\n");
    printf("MÂO INICIAL: \n");
    printArray(cards, 10);
    printf("-------------------------\n");

    /* SELECT SORT */
    Card* cardsSelect = copyArray(cards, 10);
    SortingPayload SelectPayload = SelectSort(cardsSelect, 10);
    printf("Select Sort:\n ");
    showSortingPayload(&SelectPayload);
    free(cardsSelect);

    /* BUBBLE SORT */
    Card* cardsBubble = copyArray(cards, 10);
    SortingPayload payload = bubbleSort(cardsBubble, 10);
    free(cardsBubble);
    printf("Bubble Sort:\n ");
    showSortingPayload(&payload);

    /* INSERT SORT */
    Card* cardsInsert = copyArray(cards, 10);
    SortingPayload InsertPayload = insertSort(cardsInsert, 10);
    printf("Insert Sort:\n ");
    showSortingPayload(&InsertPayload);
    free(cardsInsert);

    /* SHELL SORT */
    Card* cardsShell = copyArray(cards, 10);
    SortingPayload ShellPayload = shellSort(cardsShell, 10);
    printf("Shell Sort:\n ");
    showSortingPayload(&ShellPayload);
    free(cardsShell);

    /* QUICK SORT */
    Card* cardsQuick = copyArray(cards, 10);
    SortingPayload QuickPayload = quickSortWrapper(cardsQuick, 10);
    printf("Quick Sort:\n ");
    showSortingPayload(&QuickPayload);
    free(cardsQuick);

    /* HEAP SORT */
    Card* cardsHeap = copyArray(cards, 10);
    SortingPayload HeapPayload = heapSort(cardsHeap, 10);
    printf("Heap Sort:\n ");
    showSortingPayload(&HeapPayload);
    free(cardsHeap);
}