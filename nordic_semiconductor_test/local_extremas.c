//
// Created by michal on 02.05.18.
//

#include "local_extremas.h"

void find_extremas(int *tab, int size) {
    long int previous = tab[1] - tab[0];
    for (int i = 2; i < size; i++) {
        long int actual = tab[i] - tab[i - 1];
        if (previous < 0 && actual > 0) printf("Local min=%d\n", tab[i - 1]);
        if (previous > 0 && actual < 0) printf("Local max=%d\n", tab[i - 1]);
        if (actual == 0) continue;
        previous = actual;

    }
}