#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "./sorting/sort.h"


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

    sort(cards);


}

void startFileMode() {

}