#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string s = "examplex string";
  std::replace(s.begin(), s.end(), 'x', 'y'); // replace all 'x' to 'y'
  std::cout << s;
}
