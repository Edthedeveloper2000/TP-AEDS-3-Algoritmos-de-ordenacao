/* Definição de cores */
#define AZUL "Azul"
#define AMARELO "Amarelo"
#define VERDE "Verde"
#define VERMELHO "Vermelho"

/* Definição de cartas especiais */

#define BLOQUEAR "pular"
#define CORINGA "coringa"
#define VOLTAR "voltar"
#define MAIS_2 "+2"
#define MAIS_4 "+4"

typedef struct {
    char color[10];
    char value[10];
    int colorId;
    int valueId;
} Card;

void initializeCard(Card *card, char *color, char *value);

char getColor(Card *card);
void setColor(Card *card, char *color);

char getValue(Card *card);
void setValue(Card *card, char *value);

int getColorId(Card *card);
void setColorId(Card *card, char *color);

int getValueId(Card *card);
void setValueId(Card *card, char *value);

void showCard(Card *card);

