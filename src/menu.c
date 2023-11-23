#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "./sorting/bubbleSort/bubble.h"
#include "./sorting/selectSort/select.h"
#include "./sorting/InsertSort/insert.h"
#include "./sorting/shellSort/shell.h"
#include "./sorting/quickSort/quick.h"
#include "./sorting/heapSort/heap.h"


void showInitialMenu() {
    int mode;
    printf("Como deseja inserir as cartas? \n");
    printf("1 - Modo interativo \n");
    printf("2 - Modo de leitura de arquivo \n");

    scanf("%d", &mode);

    mode == 1 ?  startInteractiveMode() : startFileMode();
    
}
// Modo Interativo
void startInteractiveMode() {
    Card cards[10];
    char color[10];
    char value[10];

     printf("Informe cor e valor de 10 cartas: ex: (Azul 1)\n");
    for(int i = 0; i<10;i++) {
        Card currentCard;
        scanf("%s %s", color, value);
        initializeCard(&currentCard, color, value);
        cards[i] = currentCard;
    }

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

void startFileMode() {

}

// Cópia das cartas iniciais
Card* copyArray(const Card* source, int size) {
    Card* copy = malloc(size * sizeof(Card));
    if (copy == NULL) {
        exit(EXIT_FAILURE);
    }
    memcpy(copy, source, size * sizeof(Card));
    return copy;
}