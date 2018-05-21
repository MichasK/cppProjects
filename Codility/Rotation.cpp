// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size()%K==0) return A;
    int shifts = A.size()%K+1;
    for (int i=0;i<shifts;i++){
        auto last = A.back();
        for(int i=A.size();i>=0;i--){
            A[i]=A[i-1];
        }
        A[0]=last;
            
    }
    return A;
    
} 
