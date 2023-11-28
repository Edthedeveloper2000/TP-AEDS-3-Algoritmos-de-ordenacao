#include "../Card/card.h" 

#ifndef CARD_LIST_H
#define CARD_LIST_H

#define DECK_SIZE 56 // tamanho do baralho

/**
 * Cria um baralho de 56 cartas de UNO
 * @param cardlist - array que irá receber as cartas do baralho
*/
void createCards(Card *cardslist);

/**
 * Cria um baralho aleatório de 56 cartas de UNO
 * @param cardlist - array que irá receber as cartas do baralho
*/
void createRandomDeck(Card *cardsList);

/**
 * Seleciona o número informado de cartas de um baralho e povoa 
 * a lista de cartas passada como destino com elas
 * @param sourceDeck - array do qual as cartas serão selecionadas
 * @param destinyDeck - array que irá receber as cartas
 * @param amount - quantidade de cartas
*/
void selectAmountCards(Card* sourceDeck, Card* destinyDeck, int amount);


#endif // CARD_LIST_H
