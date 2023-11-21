#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "./sorting/bubbleSort/bubble.h"

int main() {
    setlocale(LC_ALL, "en_US.utf8");
     Card arr[] = {{VERMELHO, "2", 3, 2}, {AZUL, "3", 4, 3}, {VERDE, "3", 1, 3}, {VERMELHO, "1", 3, 1}, {VERDE, "1", 1, 1}};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    
    /*printf("Bubble Sort");
    for (int x = 0; x < n; x ++){
        showCard(arr);
    }*/
    
}