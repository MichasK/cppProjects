//
// Created by michal on 27.04.18.
//

#ifndef C_TRAINEE_BASIC_ALGO_H
#define C_TRAINEE_BASIC_ALGO_H

#include <stdbool.h>

int factorial_recursion(int);
int factorial_iteratively(int);
void print_tree(int n);
void print_multiply_matrix(int rows,int cols);
void remove_digit(char[],char);
void remove_whitespace(char[],int size);
char * isElement(char *tab, char character);
int search_zeros(int a,int b, int c, double * x1, double * x2);
bool isEqual(char[],char[]);
bool isPalindrome(char[],int);
int newton(int, int);
int *add(int*,int,int);
char deleteFirstChar(char** pstr);
#endif //C_TRAINEE_BASIC_ALGO_H
