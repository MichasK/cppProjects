// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> prefix_sum_vec;
    prefix_sum_vec.push_back(0);
    for(const auto x:A){
        prefix_sum_vec.push_back(x+prefix_sum_vec.back());
    }
    int passing_cars=0;
    for(unsigned int i=0;i<A.size();i++){
        if(A[i]==0){
            passing_cars += prefix_sum_vec.back()-prefix_sum_vec[i];
        }
    }
    if (passing_cars>1000000000) return -1;
    else return passing_cars;
}