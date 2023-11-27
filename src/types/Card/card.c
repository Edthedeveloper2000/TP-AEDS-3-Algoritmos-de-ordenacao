#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "card.h"

void initializeCard(Card *card, char *color, char *value) {
    setColor(card, color);
    setValue(card, value);
}

char * getColor(Card *card) {
    return card->color;
}
void setColor(Card *card, char *color) {
    strcpy(card->color, color);
    setColorId(card, color);
}

char * getValue(Card *card) {
    return card->value;
}
void setValue(Card *card, char *value) {
    strcpy(card->value, value);
    setValueId(card, value);
}

int getColorId(Card *card) {
    return card->colorId;
}

void setColorId(Card *card, char *color) {
    if(strcmp(color, GREEN) == 0) {
        card->colorId = 1;
    } else if (strcmp(color, YELLOW) == 0) {
        card->colorId = 2;
    } else if (strcmp(color, RED) == 0) {
        card->colorId = 3;
    } else if (strcmp(color, BLUE) == 0)  {
        card->colorId = 4;
    } else {
        card->colorId = 5;
    }
}


int getValueId(Card *card) {
    return card->valueId;
}

char* intToCardValue(int valueId) {
    char* result = (char*)malloc(CARDS_LIST_SIZE * sizeof(char));

    switch (valueId) {
        case 0:
            strcpy(result, "0");
            break;
        case 1:
            strcpy(result, "1");
            break;
        case 2:
            strcpy(result, "2");
            break;
        case 3:
            strcpy(result, "3");           
            break;
        case 4:
            strcpy(result, "4");
            break;
        case 5:
            strcpy(result, "5");
            break;
        case 6:
            strcpy(result, "6");
            break;
        case 7:
            strcpy(result, "7");
            break;
        case 8:
            strcpy(result, "8");
            break;
        case 9:
            strcpy(result, "9");
            break;
        case 10:
            strcpy(result, BLOCK);
            break;
        case 11:
            strcpy(result, GOBACK);
            break;
        case 12:
            strcpy(result, PLUS_TWO);
            break;
        case 13:
            strcpy(result, PLUS_FOR);
            break;
        case 14:
            strcpy(result, JOKER);
            break;
        default:
            strcpy(result, "inválido");
    }

    return result;
}

void setValueId(Card *card, char *value) {
    if (strcmp(value, "0") == 0) {
        card->valueId = 0;
    } else if (strcmp(value, "1") == 0) {
        card->valueId = 1;
    } else if (strcmp(value, "2") == 0) {
        card->valueId = 2;
    } else if (strcmp(value, "3") == 0) {
        card->valueId = 3;
    } else if (strcmp(value, "4") == 0) {
        card->valueId = 4;
    } else if (strcmp(value, "5") == 0) {
        card->valueId = 5;
    } else if (strcmp(value, "6") == 0) {
        card->valueId = 6;
    } else if (strcmp(value, "7") == 0) {
        card->valueId = 7;
    } else if (strcmp(value, "8") == 0) {
        card->valueId = 8;
    } else if (strcmp(value, "9") == 0) {
        card->valueId = 9;
    } else if (strcmp(value, BLOCK) == 0) {
        card->valueId = CARDS_LIST_SIZE;
    } else if (strcmp(value, GOBACK) == 0) {
        card->valueId = 11;
    } else if (strcmp(value, PLUS_TWO) == 0) {
        card->valueId = 12;
    } else if (strcmp(value, PLUS_FOR) == 0) {
        card->valueId = 13;
    } else if (strcmp(value, JOKER) == 0) {
        card->valueId = 14;
    }
}


void showCard(Card *card) {
    printf("%s %s", getColor(card), getValue(card));
}