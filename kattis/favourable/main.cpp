#include <iostream>
#include <vector> 
#include <string>
#include <regex>
#include <map>
#include <cstdint>


using namespace std ;

bool isNumber(std::string x) {
    regex e("^-?\\d+");
    if (regex_match (x,e)) return true;
    else return false;
}
struct Page {
    int number ;
    int a, b, c ;
} ;

int travelBook(map<int, Page> &pages, uint64_t results[], bool visited[], int current_page) {
    if (visited[current_page]) {
        return results[current_page] ;
    }

    uint64_t good_results = travelBook(pages, results, visited, pages[current_page].a) +
        travelBook(pages, results, visited, pages[current_page].b) +
        travelBook(pages, results, visited, pages[current_page].c) ;
    results[current_page] = good_results ;
    visited[current_page] = true ;
    return good_results ;
}

int main() {

    int cases ;
    cin >> cases ;

    for (int c = 0 ; c < cases ; c++ ) {
        uint64_t results[401] ;
        bool visited[401] ;
        for (int i = 0; i < 401; i++) {
            visited[i] = false ;
        }
        
        map<int, Page> pages ;
        
        int page_count ;
        cin >> page_count ;
        for ( int p = 0 ; p < page_count ; p++ ) {
            Page page ;
            string word ;
            cin >> page.number ;
            cin >> word ;
            if (isNumber(word)) {
                page.a = stoi(word) ;
                cin >> page.b >> page.c ;
            } else {
                visited[page.number] = true ;
                if (word == "favourably") {
                    results[page.number] = 1 ;
                } else {
                    results[page.number] = 0 ;
                }
            }

            pages.insert( pair<int, Page>(page.number, page) ) ;
        }
        uint64_t good_endings = travelBook(pages, results, visited, 1) ;
        cout << good_endings << endl ;
    }


    return 0 ;
}