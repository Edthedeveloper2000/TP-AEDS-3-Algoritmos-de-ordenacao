#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "menu.h"

int main() {
    setlocale(LC_ALL, "en_US.utf8");
    showInitialMenu();
}