//
// Created by michal on 27.04.18.
//

#ifndef NORDIC_SEMICONDUCTOR_TEST_MAX_NUM_FROM_DIGITS_H
#define NORDIC_SEMICONDUCTOR_TEST_MAX_NUM_FROM_DIGITS_H
long int max_num_from_digits(long int);//Get maximum number wich can be created using digits of given number
struct extremas{
    int minima;
    int maxima;
};
struct extremas find_extremas(int*,int);
#endif //NORDIC_SEMICONDUCTOR_TEST_MAX_NUM_FROM_DIGITS_H
