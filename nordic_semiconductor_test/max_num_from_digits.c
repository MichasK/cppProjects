//
// Created by michal on 27.04.18.
//

#include "max_num_from_digits.h"
#include "sorts_lib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



int ten_to_power(int x) {
    if (x == 0) return 1;
    else return 10 * ten_to_power(x - 1);
};

long int max_num_from_digits(long int num) {
    int digits = 0;
    if (num < 0) digits = 1;
    int num_cpy = num;
    while (num_cpy) {
        num_cpy /= 10;
        digits++;
    }
    int *sep_num = (int *) malloc(digits * sizeof(int));
    int i = 0;
    for (i; i < digits; i++) {
        int digit = num % 10;
        num = num / 10;
        sep_num[i] = digit;
    }
    buble_sort(sep_num,digits);
    int result = 0;
    for (int tmp = i - 1; tmp >= 0; tmp--) result += sep_num[tmp] * ten_to_power(tmp);
    return result;

}

int difference_sign_change(int x1, int x2, int x3) {
    if ((x2 > x1 && x3 > x2) || (x2 < x1 && x3 < x2)) return 0;
    if (x2 < x1 && x3 > x1) return -1;//
    if (x2 > x1 && x3 < x2) return 1;//
}

struct extremas find_extremas(int *tab, int tab_length) {
    struct extremas extremas;
    for (int i = 1; i < tab_length - 1;i++) {
        if (difference_sign_change(tab[i - 1], tab[i], tab[i + 1]) == 1) extremas.maxima++;
        if (difference_sign_change(tab[i - 1], tab[i], tab[i + 1]) == -1) extremas.maxima--;
    }

}