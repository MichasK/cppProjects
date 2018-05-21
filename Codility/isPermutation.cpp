// you can use includes, for example:
// #include <algorithm>
#include <numeric>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B(A.size());
    for(auto x:A){
        if(x>A.size())
            return 0;
        B[x-1] +=1;
    }
    for(auto y:B){
        if(y!=1)
            return 0;
    }
    return 1;
} 
