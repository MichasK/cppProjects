//
// Created by michal on 27.04.18.
//
#include <stdbool.h>
#include <stdio.h>
void buble_sort(int *tab, int tab_length) {
    bool was_any_swap = true;
    while (was_any_swap) {
        was_any_swap = false;
        for (int i = 0; i < tab_length-1; i++) {
            if (tab[i + 1] < tab[i]) {
                was_any_swap = true;
                tab[i] = tab[i] + tab[i+1];
                tab[i+1] = tab[i] - tab[i+1];
                tab[i] = tab[i]-tab[i+1];
            } else continue;
        }

    }

}

void quick_sort(int *tab, int left, int right) {
    int pivot = tab[(left + right) / 2];
    int i = left;
    int j = right;
    do {
        while (tab[i] < pivot) i++;
        while (tab[j] > pivot) j--;
        if (i <= j) {
            int tmp = tab[j];
            tab[j] = tab[i];
            tab[i] = tmp;
            j--;
            i++;
        }
    } while (i <= j);
    if (j > left) quick_sort(tab, left, j);
    if (i < right) quick_sort(tab, i, right);
}

void insert_sort(int* tab, int tab_length){
    int i,key,j;
    for(i=1;i<tab_length;i++){
        key = tab[i];
        j = i-1;
        while (j>=0 && tab[j]>key){
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = key;
    }
}