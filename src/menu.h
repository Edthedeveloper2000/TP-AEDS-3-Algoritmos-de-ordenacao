#include "./types/Card/card.h"
#include "./types/CardsList/cardsList.h"

/**
 * Mostra o menu inicial com a opção de
 * escolher o modo de ordenação
*/
void showInitialMenu();

/**
 * Inicia o modo aleatório, pelo qual as
 * cartas a serem ordenadas são geradas
 * aleatóriamente
*/
void startRandomMode();

/**
 * Inicia o modo de arquivo, no qual as cartas
 * a serem ordenadas são lidas pelo arquivo especificado.
*/
void startFileMode();