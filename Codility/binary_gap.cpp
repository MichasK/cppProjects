// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int max_gap=0;
    bool counting_starter = false;
    int counter = 0 ;
    while(N!=0){
        int bit = N%2;
       if(bit==1){
           if(counting_starter = false){
               counting_starter = true;
           }
           else{
               if(counter>max_gap){
                   max_gap=counter;
               }
               counter=0;
           }
       }
       else{ 
           if(counting_starter = true){
               counter += 1;
           }
       }
       N = N/2;
    }
    return max_gap;
} 
