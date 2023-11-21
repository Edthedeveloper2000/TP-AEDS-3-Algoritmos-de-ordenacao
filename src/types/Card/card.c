#include <string.h>
#include <stdio.h>
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
}

int getColorId(Card *card) {
    return card->colorId;
}

void setColorId(Card *card, char *color) {
    if(strcmp(color, VERDE)) {
        card->colorId = 1;
    } else if (strcmp(color, AMARELO)) {
        card->colorId = 2;
    } else if (strcmp(color, VERMELHO)) {
        card->colorId = 3;
    } else if (strcmp(color, AZUL))  {
        card->colorId = 4;
    }else {
        card->colorId = 5;
    }
}

int getValueId(Card *card) {
    return card->valueId;
}
void setValueId(Card *card, char *value) {
     if(strcmp(value, "0")) {
        card->valueId = 1;
    } else if (strcmp(value, "\01")) {
        card->valueId = 2;
    } else if (strcmp(value, "\02")) {
        card->valueId = 3;
    } else if (strcmp(value, "\03"))  {
        card->valueId = 4;
    } else if (strcmp(value, "\04"))  {
        card->valueId = 4;
    } else if (strcmp(value, "\05"))  {
        card->valueId = 5;
    } else if (strcmp(value, "\06"))  {
        card->valueId = 6;
    } else if (strcmp(value, "\07"))  {
        card->valueId = 7;
    } else if (strcmp(value, "\08"))  {
        card->valueId = 8;
    } else if (strcmp(value, "\09")) {
        card->valueId = 9;
    } else if (strcmp(value, BLOQUEAR)) {
        card->valueId = 10;
    } else if (strcmp(value, VOLTAR))  {
        card->valueId = 11;
    } else if (strcmp(value, MAIS_2))  {
        card->valueId = 12;
    } else if (strcmp(value, MAIS_4))  {
        card->valueId = 13;
    } else if (strcmp(value, CORINGA))  {
        card->valueId = 14;
    }
}

void showCard(Card *card) {
    printf("%s %s", getColor(card), getValue(card));
}