#include "../Card/card.h" 

#ifndef CARD_LIST_H
#define CARD_LIST_H

#define DECK_SIZE 56

void createCards(Card *cardslist);

void createRandomDeck(Card *cardsList);

void selectAmountCards(Card* sourceDeck, Card* destinyDeck, int amount);


#endif // CARD_LIST_H
