#include <iostream>
#include <vector>

// TL
/*
int Partition(std::vector<int>& values, int l, int r) {
  int x = values[r];
  int less = l;

  for (int i = l; i < r; ++i) {
    if (values[i] <= x) {
        std::swap(values[i], values[less]);
      ++less;
    }
  }
  std::swap(values[less], values[r]);
  return less;
}
*/

int Partition2(std::vector<int>& vec, int l, int r) {
     int v = vec[(l + r) / 2];
     int i = l;
     int j = r;
     while (i <= j) {
        while (vec[i] < v) {
           i++;
        }
        while (vec[j] > v) {
           j--;
        }
        if (i >= j) break;
        std::swap(vec[i++], vec[j--]);
     }
     return j;
}

void QuickSort(std::vector<int>& values, int l, int r) {
  if (l < r) {
    int q = Partition2(values, l, r);
    QuickSort(values, l, q - 1);
    QuickSort(values, q + 1, r);
  }
}

void QuickSort(std::vector<int>& values) {
  if (!values.empty()) {
    QuickSort(values, 0, values.size() - 1);
  }
}

int main() {

    /*
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x: vec) std::cin >> x;
    */
    std::vector<int> vec{1,2,3,7,9,3,4,8,12,0,5};
    QuickSort(vec);
    for (auto& x: vec) std::cout << x << " ";

}

