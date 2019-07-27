#include <iostream>
#include <vector> 
#include <string>
#include <regex>
#include <map>


using namespace std ;

bool isNumber(std::string x) {
    regex e("^-?\\d+");
    if (regex_match (x,e)) return true;
    else return false;
}
struct Page {
    int number ;
    int a, b, c ;
    bool ending, favorable ;
} ;

int travelBook(map<int, Page> &pages, int results[], int current_page) {
    if (results[current_page] >= 0) {
        return results[current_page] ;
    }

    int good_results = travelBook(pages, results, pages[current_page].a) +
        travelBook(pages, results, pages[current_page].b) +
        travelBook(pages, results, pages[current_page].c) ;
    results[current_page] = good_results ;
    return good_results ;
}

int main() {


    int cases ;
    cin >> cases ;

    for (int c = 0 ; c < cases ; c++ ) {
        int results[401] ;
        for (int i = 0; i < 401; i++) {
            results[i] = -1 ;
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
                page.ending = false ;
            } else {
                page.ending = true ;
                page.favorable = word == "favourably" ;
                if (word == "favourably") {
                    results[page.number] = 1 ;
                } else {
                    results[page.number] = 0 ;
                }
            }

            pages.insert( pair<int, Page>(page.number, page) ) ;
        }
        int good_endings = travelBook(pages, results, 1) ;
        cout << good_endings << endl ;
    }


    return 0 ;
}