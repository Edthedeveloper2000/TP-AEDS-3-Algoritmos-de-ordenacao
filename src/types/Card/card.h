#ifndef CARD_H
#define CARD_H

/* Definição de cores */
#define VERDE "Verde" // colorId 1
#define AMARELO "Amarelo" // colorId 2
#define VERMELHO "Vermelho" // colorId 3
#define AZUL "Azul" // colorId 4
#define PRETO "Preto" // colorId 5

/* Definição de cartas especiais */

#define BLOQUEAR "Pular" // valueId 10
#define VOLTAR "Voltar" // valueId 11
#define MAIS_2 "+2" // valueId 12 
#define MAIS_4 "+4" // valueId 13
#define CORINGA "Coringa" // valueId 14

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
