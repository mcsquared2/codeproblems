#include <iostream>
#include <vector>

using namespace std ;
int main() {

    int cases ;
    cin >> cases ;
    for (int c = 0; c < cases; c++) {
        int m, n ;
        cin >> n >> m ;
        vector<unsigned int> a ;
        unsigned int k, max = 0, sum = 0 ;
        // cout << "Max is " << max << endl ;
        for (int i = 0; i < n; i++) {
            cin >> k ;
            if (k == m) {
                a.push_back(sum) ;
                sum = 0 ;
            } else {
                sum += k ;
            }
            
        }
        a.push_back(sum) ;
        for (size_t i = 0; i < a.size()-1; i++) {
            k = a[i] + m + a[i+1] ;
            if (max < k) {
                max = k ;
            }
        }
        cout << max << endl ;
    }

    return 0;
}