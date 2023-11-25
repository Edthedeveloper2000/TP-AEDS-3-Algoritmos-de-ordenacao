#ifndef CARD_H
#define CARD_H

/* Definição de cores */
#define GREEN "Verde" // colorId 1
#define YELLOW "Amarelo" // colorId 2
#define RED "Vermelho" // colorId 3
#define BLUE "Azul" // colorId 4
#define BLACK "Preto" // colorId 5

/* Definição de cartas especiais */

#define BLOCK "Pular" // valueId 10
#define GOBACK "Voltar" // valueId 11
#define PLUS_TWO "+2" // valueId 12 
#define PLUS_FOR "+4" // valueId 13
#define JOKER "Coringa" // valueId 14

typedef struct {
    char color[10];
    char value[10];
    int colorId;
    int valueId;
} Card;

void initializeCard(Card *card, char *color, char *value);

char * getColor(Card *card);
void setColor(Card *card, char *color);

char * getValue(Card *card);
void setValue(Card *card, char *value);

int getColorId(Card *card);
void setColorId(Card *card, char *color);

int getValueId(Card *card);
void setValueId(Card *card, char *value);

void showCard(Card *card);

#endif // CARD_H
