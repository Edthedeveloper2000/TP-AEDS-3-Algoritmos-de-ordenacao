#include "swap.h"

void swap(Card *card_1, Card *card_2) {
    Card temp = *card_1;
    *card_1 = *card_2;
    *card_2 = temp;
}