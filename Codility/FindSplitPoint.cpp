// you can use includes, for example:
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto N = A.size();
    if (N==1) return A[0];
    if (N==2) return abs(A[1]-A[0]);
    long long int  left_sum=0;
    long long int  right_sum=0;
    int sum = std::accumulate(A.begin(), A.end(), 0);
    long long int solution=0;
    for( unsigned int i=0; i<N-1;i++){
        left_sum += A[i];
        right_sum =sum - left_sum;
        auto difference = abs(left_sum-right_sum);
        if(!i){
            solution = difference;
        }else {
            if(difference<=solution){
                solution = difference;
            }
        }
    }
    return solution;
} 
