#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "./sorting/bubbleSort/bubble.h"
#include "./sorting/selectSort/select.h"

void showInitialMenu() {
    int mode;
    printf("Como deseja inserir as cartas? \n");
    printf("1 - Modo interativo \n");
    printf("2 - Modo de leitura de arquivo \n");

    scanf("%d", &mode);

    mode == 1 ?  startInteractiveMode() : startFileMode();
    
}

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

    printf("Carta de exemplo: \n cor: %s \n valor: %s \n valueId %d colorId %d \n", cards[1].color, cards[1].value, cards[1].valueId, cards[1].colorId);

    printf("MÂO INICIAL: \n");
    printArray(cards, 10);

    SortingPayload payload = bubbleSort(cards, 10);

    printf("Bubble Sort:\n ");
    showSortingPayload(&payload);

    SortingPayload SelectPayload = SelectSort(cards, 10);

    printf("Select Sort:\n ");
    showSortingPayload(&SelectPayload);
}

void startFileMode() {

}