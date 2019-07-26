#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

struct Minion {
    int low ;
    int high ;
} ;

bool minion_sorter (Minion const& lhs, Minion const& rhs) {
    return lhs.high < rhs.high ;
}

int main() {
    
    int minion_count ;
    cin >> minion_count ;
    vector<Minion> minions ;
    for (int i = 0 ; i < minion_count ; i++) {
        Minion minion ;
        cin >> minion.low >> minion.high ;
        minions.push_back(minion) ;
    }

    sort(minions.begin(), minions.end(), &minion_sorter) ;

    int rooms = 1;
    int threshold = minions[0].high ;
    for (size_t i = 0 ; i < minions.size() ; i++) {
        if (minions[i].low > threshold) {
            rooms++ ;
            threshold = minions[i].high ;
        }
    }


    cout << rooms ;
    return 0;
}