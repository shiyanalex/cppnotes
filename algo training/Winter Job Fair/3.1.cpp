#include <iostream>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; ++i)

int nod(int m, int n) {
  return n ? nod(n, m % n) : m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> vec(n);
    for (auto& x: vec) cin >> x;


    vector<vector<int>> table(n, vector<int>(n));

    forn(i, n) {
    table[i][i] = 0;
    }

  forn(i, n) {
    for (int j = i - 1; j >= 0; --j) {
      table[i][j] = table[i][j + 1];

      if (vec[j] < vec[i]) {
        ++table[i][j];
      }
    }

    for (int j = i + 1; j < n; ++j) {
      table[i][j] = table[i][j - 1];

      if (vec[i] < vec[j]) {
        table[i][j]++;
      }
    }
  }

//  forn(i, n) {
//    forn(j, n) {
//      cout << table[i][j] << ' ';
//    }
//
//    cout << '\n';
//  }

  int startInversions = 0;

  forn(i, n) {
    for (int j = i + 1; j < n; ++j) {
      if (vec[j] < vec[i]) {
        ++startInversions;
      }
    }
  }


  int c2n = n * (n - 1) / 2;
  int totalInversions = c2n * startInversions;

  forn(i, n) {
    for (int j = i + 1; j < n; ++j) {
      int cp = totalInversions;

      if (vec[i] < vec[j]) {
        ++totalInversions;
      }

      if (vec[i] > vec[j]) {
        --totalInversions;
      }

      int leftPlusInversions = table[i][j - 1];
      int leftMinusInversions = j - 1 - i - table[i][j - 1];

      int rightPlusInversions = table[j][i + 1];
      int rightMinusInversions = j - 1 - i - table[j][i + 1];

      totalInversions += leftPlusInversions - leftMinusInversions + rightPlusInversions - rightMinusInversions;

      //cout << i << ' ' << j << ' ' << totalInversions - cp << '\n';
    }
  }

  int nod1 = nod(totalInversions, c2n);

  cout << totalInversions / nod1 << '/' << c2n / nod1 << '\n';
  return 0;
}
