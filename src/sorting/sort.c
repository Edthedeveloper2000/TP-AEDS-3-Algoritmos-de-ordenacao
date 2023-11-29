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

#define CARDS_LIST_SIZE 10

void sort(Card cards[], int testNumber){
    printf("Teste Nº: %d\n", testNumber + 1);
    printf("-------------------------\n");
    printf("MÂO INICIAL: \n");
    showCards(cards, CARDS_LIST_SIZE);
    printf("-------------------------\n");

    /* SELECT SORT */
    Card* cardsSelect = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload SelectPayload = SelectSort(cardsSelect, CARDS_LIST_SIZE);
    printf("Select Sort:\n ");
    showSortingPayload(&SelectPayload);
    free(cardsSelect);

    /* BUBBLE SORT */
    Card* cardsBubble = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload bubbleSortPayload = bubbleSort(cardsBubble, CARDS_LIST_SIZE);
    printf("Bubble Sort:\n ");
    showSortingPayload(&bubbleSortPayload);
    free(cardsBubble);

    /* INSERT SORT */
    Card* cardsInsert = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload InsertPayload = insertSort(cardsInsert, CARDS_LIST_SIZE);
    printf("Insert Sort:\n ");
    showSortingPayload(&InsertPayload);
    free(cardsInsert);

    /* SHELL SORT */
    Card* cardsShell = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload ShellPayload = shellSort(cardsShell, CARDS_LIST_SIZE);
    printf("Shell Sort:\n ");
    showSortingPayload(&ShellPayload);
    free(cardsShell);

    /* QUICK SORT */
    Card* cardsQuick = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload QuickPayload = quickSortWrapper(cardsQuick, CARDS_LIST_SIZE);
    printf("Quick Sort:\n ");
    showSortingPayload(&QuickPayload);
    free(cardsQuick);

    /* HEAP SORT */
    Card* cardsHeap = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload HeapPayload = heapSort(cardsHeap, CARDS_LIST_SIZE);
    printf("Heap Sort:\n ");
    showSortingPayload(&HeapPayload);
    free(cardsHeap);
}