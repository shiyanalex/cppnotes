//#define _GLIBCXX_DEBUG
#define yep cout << "YES\n"
#define nope cout << "NO\n"

#define forn(i, n) for (long long i = 0; i < (long long)n; ++i)

#include <iostream>
#include <vector>

#pragma GCC optimize("Ofast,unroll-loops")

using namespace std;

const char el = '\n';

long long nod(long long m, long long n)
{
  return n ? nod(n, m % n) : m;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n; cin >> n;

  vector<long long> arr(n);

  forn(i, n) {
    cin >> arr[i];
  }

  vector<vector<long long>> table(n, vector<long long>(n));

  forn(i, n) {
    table[i][i] = 0;
  }

  forn(i, n) {
    for (long long j = i - 1; j >= 0; --j) {
      table[i][j] = table[i][j + 1];

      if (arr[j] < arr[i]) {
        ++table[i][j];
      }
    }

    for (long long j = i + 1; j < n; ++j) {
      table[i][j] = table[i][j - 1];

      if (arr[i] < arr[j]) {
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

  long long startInversions = 0;

  forn(i, n) {
    for (long long j = i + 1; j < n; ++j) {
      if (arr[j] < arr[i]) {
        ++startInversions;
      }
    }
  }


  long long c2n = n * (n - 1) / 2;
  long long totalInversions = c2n * startInversions;

  forn(i, n) {
    for (long long j = i + 1; j < n; ++j) {
      long long cp = totalInversions;

      if (arr[i] < arr[j]) {
        ++totalInversions;
      }

      if (arr[i] > arr[j]) {
        --totalInversions;
      }

      long long leftPlusInversions = table[i][j - 1];
      long long leftMinusInversions = j - 1 - i - table[i][j - 1];

      long long rightPlusInversions = table[j][i + 1];
      long long rightMinusInversions = j - 1 - i - table[j][i + 1];

      totalInversions += leftPlusInversions - leftMinusInversions + rightPlusInversions - rightMinusInversions;

      //cout << i << ' ' << j << ' ' << totalInversions - cp << '\n';
    }
  }

  long long nod1 = nod(totalInversions, c2n);

  cout << totalInversions / nod1 << '/' << c2n / nod1 << '\n';

  return 0;
}
