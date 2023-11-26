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


void fsort(Card cards[]){
    FILE* output;

    output = fopen("src/tests/output.txt", "w");
    if(output == NULL){
          printf("Falha ao processar o Arquivo");
        exit(EXIT_FAILURE);
    }
    fprintf(output, "MAO INICIAL: \n");
    fprintf(output, "Mao de cartas: \n");
    
    // SELECT SORT
    Card* cardsSelect = copyArray(cards, 10);
    SortingPayload SelectPayload = SelectSort(cardsSelect, 10);
    fprintf(output, "Select Sort:\n");
    showSortingPayloadFile(&SelectPayload, output);
    free (cardsSelect);

    // BUBBLE SORT
    Card* cardsBubble = copyArray(cards, 10);
    SortingPayload BubblePayload = bubbleSort(cardsBubble, 10);
    fprintf(output, "Bubble Sort:\n");
    showSortingPayloadFile(&BubblePayload, output);
    free (cardsBubble);

    // INSERT SORT
    Card* cardsInsert = copyArray(cards, 10);
    SortingPayload InsertPayload = insertSort(cardsInsert, 10);
    fprintf(output, "Insert Sort:\n");
    showSortingPayloadFile(&InsertPayload, output);
    free (cardsInsert);

    // SHELL SORT
    Card* cardsShell = copyArray(cards, 10);
    SortingPayload ShellPayload = shellSort(cardsShell, 10);
    fprintf(output, "Shell Sort:\n");
    showSortingPayloadFile(&ShellPayload, output);
    free (cardsShell);

    // QUICK SORT
    Card* cardsQuick = copyArray(cards, 10);
    SortingPayload QuickPayload = quickSortWrapper(cardsQuick, 10);
    fprintf(output, "Quick Sort:\n");
    showSortingPayloadFile(&QuickPayload, output);
    free (cardsQuick);

    // HEAP SORT
    Card* cardsHeap = copyArray(cards, 10);
    SortingPayload HeapPayload = heapSort(cardsHeap, 10);
    fprintf(output, "Heap Sort:\n");
    showSortingPayloadFile(&HeapPayload, output);
    free (cardsHeap);

    fclose(output);
;
;
;
}