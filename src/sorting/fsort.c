#include <stdio.h>
#include <stdlib.h>
#include "fsort.h"
#include "../utils/copyArray/copyArray.h"
#include "./bubbleSort/bubble.h"
#include "./selectSort/select.h"
#include "./InsertSort/insert.h"
#include "./shellSort/shell.h"
#include "./quickSort/quick.h"
#include "./heapSort/heap.h"

#define CARDS_LIST_SIZE 10


void fsort(Card cards[], int testNumber){
    FILE* output;

    output = testNumber == 0 ? fopen("src/tests/output.txt", "w") :  fopen("src/tests/output.txt", "a");
    if(output == NULL){
          printf("Falha ao processar o Arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(output, "Teste Nº: %d\n", testNumber + 1);
    fprintf(output, "-------------------------\n");
    fprintf(output, "MÂO INICIAL: \n");
    fprintf(output, "Mão de cartas: \n");
    showCardsFile(cards, CARDS_LIST_SIZE, output);
    fprintf(output, "-------------------------\n");

    // SELECT SORT
    Card* cardsSelect = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload SelectPayload = SelectSort(cardsSelect, CARDS_LIST_SIZE);
    fprintf(output, "Select Sort:\n");
    showSortingPayloadFile(&SelectPayload, output);
    free (cardsSelect);

    // BUBBLE SORT
    Card* cardsBubble = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload BubblePayload = bubbleSort(cardsBubble, CARDS_LIST_SIZE);
    fprintf(output, "Bubble Sort:\n");
    showSortingPayloadFile(&BubblePayload, output);
    free (cardsBubble);

    // INSERT SORT
    Card* cardsInsert = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload InsertPayload = insertSort(cardsInsert, CARDS_LIST_SIZE);
    fprintf(output, "Insert Sort:\n");
    showSortingPayloadFile(&InsertPayload, output);
    free (cardsInsert);

    // SHELL SORT
    Card* cardsShell = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload ShellPayload = shellSort(cardsShell, CARDS_LIST_SIZE);
    fprintf(output, "Shell Sort:\n");
    showSortingPayloadFile(&ShellPayload, output);
    free (cardsShell);

    // QUICK SORT
    Card* cardsQuick = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload QuickPayload = quickSortWrapper(cardsQuick, CARDS_LIST_SIZE);
    fprintf(output, "Quick Sort:\n");
    showSortingPayloadFile(&QuickPayload, output);
    free (cardsQuick);

    // HEAP SORT
    Card* cardsHeap = copyArray(cards, CARDS_LIST_SIZE);
    SortingPayload HeapPayload = heapSort(cardsHeap, CARDS_LIST_SIZE);
    fprintf(output, "Heap Sort:\n");
    showSortingPayloadFile(&HeapPayload, output);
    free (cardsHeap);

    fclose(output);
;
;
;
}