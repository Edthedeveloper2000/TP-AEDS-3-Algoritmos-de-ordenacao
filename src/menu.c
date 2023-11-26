#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "./sorting/sort.h"
#include "./sorting/fsort.h"


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
    int outputMode = 0;

     printf("Informe cor e valor de 10 cartas: ex: (Azul 1)\n");
    for(int i = 0; i<10;i++) {
        Card currentCard;
        scanf("%s %s", color, value);
        initializeCard(&currentCard, color, value);
        cards[i] = currentCard;
    }

    printf("Modo de Saída: \n");
    printf("1 - Modo Terminal \n");
    printf("2 - Modo Arquivo \n");
    scanf("%d", &outputMode);
    
    switch (outputMode)
    {
    case 1:
        sort(cards);
        break;
    
    case 2:
        fsort(cards);
        break;
        
    default:
        break;
    }

}

void startFileMode() {
    int n = 0;
    FILE *file;

    file = fopen("src/tests/test.txt", "r");

    if (file == NULL) {
        printf("Error opening the file\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", &n);

    for (int testNumber = 0; testNumber < n; testNumber++) {
        Card cards[10];
        char color[10];
        char value[10];

        printf("Test Number: %d\n", testNumber + 1);

        for (int i = 0; i < 10; i++) {
            Card currentCard;
            // Adjusted format specifier to exclude both opening and closing parentheses
            fscanf(file, " (%s ", color);
            i != 9 ?  fscanf(file, "%9[^)]) ", value) : fscanf(file, "%9[^)])\n", value);
            initializeCard(&currentCard, color, value);
            cards[i] = currentCard;
        }

        sort(cards);
    }

    fclose(file);
}
