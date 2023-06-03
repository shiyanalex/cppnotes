#include <iostream>
#include <algorithm>
/*
int MyToLower( char r) {
switch (r) {
 case 'А': r='а'; break;
 case 'Б': r='б'; break;
 case 'В': r='в'; break;
 case 'Г': r='г'; break;
 case 'Д': r='д'; break;
 case 'Е': r='е'; break;
 case 'Ж': r='ж'; break;
 case 'З': r='з'; break;
 case 'И': r='и'; break;
 case 'Й': r='й'; break;
 case 'К': r='к'; break;
 case 'Л': r='л'; break;
 case 'М': r='м'; break;
 case 'Н': r='н'; break;
 case 'О': r='о'; break;
 case 'П': r='п'; break;
 case 'Р': r='р'; break;
 case 'С': r='с'; break;
 case 'Т': r='т'; break;
 case 'У': r='у'; break;
 case 'Ф': r='ф'; break;
 case 'Х': r='х'; break;
 case 'Ц': r='ц'; break;
 case 'Ч': r='ч'; break;
 case 'Ш': r='ш'; break;
 case 'Щ': r='щ'; break;
 case 'Ъ': r='ъ'; break;
 case 'Ы': r='ы'; break;
 case 'Ь': r='ь'; break;
 case 'Э': r='э'; break;
 case 'Ю': r='ю'; break;
 case 'Я': r='я'; break;
 }
return (r); 
} 
*/

std::string isPal(std::string S) {
    
    for (auto & c : S) {
        //MyToLower(c);
        c = tolower(c);
        std::erase(S, ' ');
    } 

    /*
    auto it = S.begin();
    while (it != S.end()) {
        *it = tolower(*it);
        ++it;
    }
    for (;;) {     
        auto it = std::find(S.begin(), S.end(), ' ');
        if (it == S.end()) break;
            S.erase(it);
    } */

    std::cout << S << "\n";
    std::string P = S;
    std::reverse(P.begin(), P.end());

    if (S == P) {
        return "Yes";
    } else {
        return "No";
    }
}


int main() {
    setlocale(LC_ALL, "RUS");
    std::string str = "ape ePa";
    
    /*
    std::string str;    
    getline (std::cin, str);
    */
    std::cout << isPal(str);
    
}
