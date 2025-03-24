#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    
    while (left < right) {
        if (!isalnum(s[left])) { left++; continue; }  // Пропускаем не буквы/цифры
        if (!isalnum(s[right])) { right--; continue; }
        
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++, right--;
    }
    
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);

}
