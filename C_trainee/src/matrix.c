//
// Created by michal on 29.04.18.
//

#include "matrix.h"
void deleteMatrix(int ***tab,int n){
    for(int i=0;i<n;i++) free((*tab)[i]);
    free(*tab);
    tab=NULL;
}

int** createMatrix(int n){
    int **tab=malloc(n * sizeof(int*));
    if(tab==NULL) return NULL;
    for (int i = 0; i < n; i++) {
        tab[i] = malloc(n * sizeof(int));
        if (tab[i] == NULL) deleteMatrix(&tab,i);
    }

    return tab;
}

void _createMatrix(int ***tab,int n){
    if(tab==NULL) return;
    if(n<1) return;
    int **array=malloc(n* sizeof(int*));
    int * values = malloc(n*n* sizeof(int));
    for(int i=0;i<n;i++){
        array[i] = values[0]+i*n;
    }
    *tab=array;

}


