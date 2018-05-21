//
// Created by michal on 27.04.18.
//

#include "basic_algo.h"
#include <stdio.h>
#include <ctype.h>
#include "math.h"
#include <stdlib.h>

int factorial_recursion(int num){
    if (num==0) return 1;
    else return num*factorial_recursion(num-1);
}

int factorial_iteratively(int num){
    int result =1;
    while(num != 1){
        result *=num;
        num--;
    }

}

void print_tree(int rows){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            putchar(' ');
        }

        for (int j = 0; j < 2 * i - 1; j++) {
            putchar('*');
        }
        printf("\n");
    }
    printf("\n");
}

void print_multiply_matrix(int rows,int cols){
    for(int i=1;i<rows+1;i++){
        for(int j=1;j<cols+1;j++){
            printf("%4d ",i*j);
        }
        printf("\n");
    }
}

void remove_digit(char text[],char digit){
    int i=0;
    do{
        if(text[i]==digit){
            for(int j=i;text[j]!='\0';j++) text[j]=text[j+1];
            i--;
        }
        i++;
    }while(text[i]!='\0');
}
void remove_whitespace(char text[] ,int size){
    int i;
    for(i=0;i<size;i++){
        if(isspace(text[i])) text[i]='\n';
        else continue;
    }
}
char * isElement(char *tab, char character){
    for(int i=0;tab[i]!='\0';i++){
        if(tab[i]==character) return &tab[i];
    }
    return NULL;
}
int search_zeros(int a,int b, int c, double * x1, double * x2){
    float delta = b*b - 4*a*c;
    if (delta==0){
        *x1=(double)(-b/(2*a));
        return 1;
    }
    if(delta>0){
        double sqrt_delta = sqrt(delta);
        *x1=(-b-sqrt_delta)/(2*a);
        *x2=(-b+sqrt_delta)/(2*a);
        return 2;
    }
    return 0;

}
bool isEqual(char text1[],char text2[]){
    for(int i =0; text1[i]!='\0' || text2[i]!='\0';i++){
        if(text1[i]!=text2[i]) return false;
    }
    return true;
}

bool isPalindrome(char text[],int length){
    if(length == 1 || length == 0) return true;
    if(text[0]!=text[length-1]) return false;
    return isPalindrome(text+1,length-2);

}
int newton(int n, int k){
    if(k==n || k==0) return 1;
    return newton(n-1,k-1) + newton(n-1,k);
}

int fibonacci_rec(int n){
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);

}
int *add(int* tab,int n,int n_elem){
    int *tmp=(int*)malloc((n+1)* sizeof(int));
    if(tmp==NULL) return NULL;
    for(int i=0; i<n;i++){
        tmp[i]=tab[i];
    }
    free(tab);
    tmp[n]=n_elem;
    return  tmp;
}
char deleteFirstChar(char** pstr){
    char removed_char = (*pstr)[0];
    int size = 0;
    while((*pstr)[size]!='\0') size++;
    char * tmp = (char*)malloc(size*sizeof(char));
    for(int i=1;i<size;i++) tmp[i-1]=(*pstr)[i];
    tmp[size]='\0';
    free(*pstr);
    *pstr = tmp;
    return removed_char;
}