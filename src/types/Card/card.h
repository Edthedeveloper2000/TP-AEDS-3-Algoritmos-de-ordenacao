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

#define CARDS_LIST_SIZE 10

typedef struct {
    char color[CARDS_LIST_SIZE];
    char value[CARDS_LIST_SIZE];
    int colorId;
    int valueId;
} Card;

/**
 * Cria uma instância de Card
 * @param *card - ponteiro para armazenar os valores da carta
 * @param *color - cor da carta
 * @param *value - valor da carta
*/
void initializeCard(Card *card, char *color, char *value);

char * getColor(Card *card);
void setColor(Card *card, char *color);

char * getValue(Card *card);
void setValue(Card *card, char *value);

int getColorId(Card *card);
void setColorId(Card *card, char *color);

/**
 * Mapeia um valor inteiro fornecido para o valor
 * correspondente da carta.
 * @param valueId - valor inteiro a ser mapeado
 * @return char* - valor da carta correspondente ao valueId
*/
char* intToCardValue(int valueId);

int getValueId(Card *card);
void setValueId(Card *card, char *value);

void showCard(Card *card);

#endif // CARD_H
