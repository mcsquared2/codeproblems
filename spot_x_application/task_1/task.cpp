// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t left_i = 0, right_i = A.size()-1 ;
    sort(A.begin(), A.end()) ;
    while (left_i != right_i) {
        // If the current left value is positive, or the current right value is negative, there isn't a match.
        if (A[left_i] >= 0 || A[right_i] <= 0){
            return 0 ;
        }
        
        if (abs(A[left_i]) == A[right_i]) {
            return A[right_i] ;
        }
        if (abs(A[left_i]) < A[right_i]) {
            right_i -=1 ;
        } else {
            left_i += 1 ;   
        }
        
    }
    return 0 ;
}
