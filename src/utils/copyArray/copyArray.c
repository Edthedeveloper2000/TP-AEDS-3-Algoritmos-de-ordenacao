#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copyArray.h"

// Cópia das cartas iniciais
Card* copyArray(const Card* source, int size) {
    Card* copy = malloc(size * sizeof(Card));
    if (copy == NULL) {
        exit(EXIT_FAILURE);
    }
    memcpy(copy, source, size * sizeof(Card));
    return copy;
}