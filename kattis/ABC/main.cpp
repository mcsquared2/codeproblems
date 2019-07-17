#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


int returnVal (char c) {
    char A = 'A' ;
    return (int) c - (int) A ;
}
int main () {
    int vals[3] ;

    std::cin >> vals[0] >> vals[1] >> vals[2] ;

    std::sort(vals, vals+3) ;

    std::string order ;
    std::cin >> order ;
    std::vector<char> cstr(order.c_str(), order.c_str() + order.size() + 1);

    for (int i = 0; i < 3; i++) {
        std::cout << vals[ returnVal(cstr[i]) ] ;
        if (i < 2) {
            std::cout << ' ' ;
        } else {
            std::cout << '\n' ;
        }
    }
    

    return 0;
}
