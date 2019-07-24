// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(int A, int B) {
    // write your code in C++14 (g++ 6.2.0)
    string result = "" ;
    if (A == B) {
        for(int i = 0; i< A; i++) {
            result += "ab" ;
        }
        return result ;
    }
    bool more_bs = false ;
    if (A < B) {
        more_bs = true ;
    }
    int ratio = A/B ;
    if (more_bs) {
        ratio = B/A ;
    }
    if (ratio > 2) {
        ratio = 2 ;
    }
    int extra = A - ratio*B ;
    if (more_bs) {
        extra = B - ratio*A ;
    }
    int doubles = 0, singles = B ;
    if (more_bs) {
        singles = A ;
    }
    if (ratio == 2) {
        doubles = B, singles = 0 ;
        if (more_bs) {
            doubles = A ;
        }   
    }
    
    
    
    if (extra > 2 && ratio == 1) {
        
        doubles = extra - 2 ;
        extra = 2 ;
        if (more_bs) {
            singles = A - doubles ;
        } else {
            singles = B - doubles ;
        }
    }
    
    
    if (more_bs) {
        for (int i = 0; i < extra; i++) {
            result += "b" ;
        }
        for (int j = 0; j < doubles; j++) {
            result += "abb" ;
        }
        for (int k = 0; k < singles; k++) {
            result += "ab" ; 
        }
    }
    else {
        for (int i = 0; i < extra; i++) {
            result += "a" ;
        }
        for (int j = 0; j < doubles; j++) {
            result += "baa" ;
        }
        for (int k = 0; k < singles; k++) {
            result += "ba" ;  
        }
    }
    return result ;
}
