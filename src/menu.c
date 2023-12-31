#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "./sorting/sort.h"
#include "./sorting/fsort.h"

#define CARDS_LIST_SIZE 10


void showInitialMenu() {
    int mode;
    printf("Como deseja inserir as cartas? \n");
    printf("1 - Modo aleatório \n");
    printf("2 - Modo de leitura de arquivo \n");

    scanf("%d", &mode);

    mode == 1 ?  startRandomMode() : startFileMode();
    
}

void startRandomMode() {
    int outputMode = 0;
    Card deck[DECK_SIZE];
    Card cards[CARDS_LIST_SIZE];
    
    createRandomDeck(deck);
    selectAmountCards(deck, cards, CARDS_LIST_SIZE);

    printf("Modo de Saída: \n");
    printf("1 - Modo Terminal \n");
    printf("2 - Modo Arquivo \n");
    scanf("%d", &outputMode);
    
    switch (outputMode)
    {
    case 1:
        sort(cards, 0);
        break;
    
    case 2:
        fsort(cards, 0);
        break;
        
    default:
        break;
    }

}

void startFileMode() {
    int n = 0;
    FILE *file;
    int outputMode = 0;
    char filePath[100];
    printf("Informe o caminho do arquivo: \n");
    scanf("%s", filePath);
    file = fopen(filePath, "r");

    if (file == NULL) {
        printf("Error opening the file\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", &n);
    printf("Modo de Saída: \n");
    printf("1 - Modo Terminal \n");
    printf("2 - Modo Arquivo \n");
    scanf("%d", &outputMode);
    

    for (int testNumber = 0; testNumber < n; testNumber++) {
        Card cards[CARDS_LIST_SIZE];
        char color[CARDS_LIST_SIZE];
        char value[CARDS_LIST_SIZE];

        for (int i = 0; i < CARDS_LIST_SIZE; i++) {
            Card currentCard;
            fscanf(file, " (%s ", color);
            // "%9[^)]) " é uma expressão regular para encontrar o valor desejado sem considerar o parentesis
            i != 9 ?  fscanf(file, "%9[^)]) ", value) : fscanf(file, "%9[^)])\n", value);
            initializeCard(&currentCard, color, value);
            cards[i] = currentCard;
        }
        switch (outputMode)
        {
        case 1:
            sort(cards, testNumber);
            break;
        
        case 2:
            fsort(cards, testNumber);
            break;
            
        default:
            break;
        }
    }

    fclose(file);
}
