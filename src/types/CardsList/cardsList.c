#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cardsList.h"

void createCards(Card * cards) {
    for (int color = 1; color <= 5; color++) {
        for (int value = 0; value <= 12; value++) {
            Card *card = &cards[(color-1) * 13 + value];
            card->colorId = color;

            char valueAsChar[10];
            strcpy(valueAsChar, intToCardValue(value));

            switch (color) {
                case 1:
                    strcpy(card->color, GREEN);
                    initializeCard(card, GREEN, valueAsChar);
                    break;
                case 2:
                    initializeCard(card, YELLOW, valueAsChar);
                    break;
                case 3:
                    initializeCard(card, RED, valueAsChar);
                    break;
                case 4:
                    initializeCard(card, BLUE, valueAsChar);
                    break;
                case 5:
                    initializeCard(card, BLACK, valueAsChar);
                    break;
            }
        }

        if (color == 5) {
            for (int value = 13; value <= 14; value++) {
                Card *card = &cards[(color-1) * 13 + value];
                switch (value) {
                    case 13:
                        initializeCard(card, BLACK, PLUS_FOR);
                        break;
                    case 14:
                        initializeCard(card, BLACK, JOKER);
                        break;
                }
            }
        }
    }
}

void createRandomDeck(Card *cardsList) {
    createCards(cardsList);
    srand(time(NULL));
    for (int x = 0; x < DECK_SIZE; x++) {
        int aux = rand() % (x + 1);
        Card temp = cardsList[x];
        cardsList[x] = cardsList[aux];
        cardsList[aux] = temp;
    }
}

void selectAmountCards(Card *sourceDeck, Card* destinyDeck, int amount) {
    for (int x = 0; x < amount; x++) {
        destinyDeck[x] = sourceDeck[x];
    }

   
}
