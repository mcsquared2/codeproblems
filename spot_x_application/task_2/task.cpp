// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> sum_0 ;
    if (N%2 == 1) {
        sum_0.push_back(0);
    }
    for (int i = 0; i<N/2; i++ ) {
        sum_0.push_back(i+1) ;
        sum_0.push_back((i+1)*-1) ;
    }
    
    return sum_0 ;
}
