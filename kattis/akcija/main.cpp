#include <algorithm>
#include <iostream>
#include <vector> 

using namespace std ;
int main() {
    int cases;
    cin >> cases ;
    vector<int> prices ;
    int price ;
    for ( int i = 0 ; i < cases ; i++ ) {
        cin >> price ;
        prices.push_back(price) ;
    }
    sort(prices.begin(), prices.end()) ;
    // cout << "Prices: " ;
    // for (size_t i = 0; i < prices.size(); i++) {
    //     cout << prices[i] << " " ;
    // }
    // cout << endl ;
    int cost = 0;
    for (size_t i = prices.size()-1; i > 1; i=i-3 ) {
        cost += prices[i] + prices[i-1] ;
        if (i <3) {
            break ;
        }
    }
    for (size_t i = 0; i < prices.size()%3; i++) {
        cost += prices[i] ;
    }
    cout << cost << std::endl ;
    return 0 ;
} 