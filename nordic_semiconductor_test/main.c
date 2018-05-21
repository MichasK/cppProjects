#include <stdio.h>
#include "local_extremas.h"
#include "max_num_from_digits.h"
int main() {
    int tab[]={2,3,3,3,4,-1,0,6,9,8};
    find_extremas(tab,10);
    return 0;
}