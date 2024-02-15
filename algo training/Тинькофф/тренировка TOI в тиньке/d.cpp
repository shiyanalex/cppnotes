#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

int nums(int x) {
    std::set<std::pair<int, int>> prev;
    for (int i = 2; i <= x; ++i) {
        if (x % i == 0 && !prev.contains({x/i, i})) prev.insert({i, x/i});
    }
    return prev.size();
}

std::multiset<int> fact_helper(std::multiset<std::multiset<int>>& dp, int x) {
    std::multiset<int> temp;
    for (int i = 2; i <= x; ++i) {
        if (x % i == 0) {
            temp.insert(i);
            temp.insert(x % i);
            fact_helper(dp, x/i);
        }
    }
    return temp;
}



int f(int n) {
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      count++;
      n /= i;
      while (n % i == 0) {
        n /= i;
        count++;
      }
    }
  }
  return count;
}

int factorize(int a) {
    std::multiset<std::multiset<int>> result;
    fact_helper(result, a);
    return result.size();
}

int f(int a, int b) {
    int ans = 0;
    for (int i = a; i <= b; ++i) {
        //ans += nums(i);
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << f22(n);
    //for (int i = 0; i < n; ++i) {
        //int a, b;
        //std::cin >> a >> b;

    //}
}
