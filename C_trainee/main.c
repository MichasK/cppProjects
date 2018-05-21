#include <stdio.h>
#include <stdlib.h>
#include "src/basic_algo.h"
#include "matrix.h"
int *f(int n){
    int *tab = (int*)malloc(n* sizeof(n));
    for(int i=0;i<n;i++) tab[i]=2*i+1;
    return tab;
}
#define fun(a) a*a*a

int main() {
    int a=11;
    int b=1;
    printf("%d",fun(a-b));
    //output is ?
}