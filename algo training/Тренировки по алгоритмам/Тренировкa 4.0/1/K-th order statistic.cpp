#include <iostream>
#include <vector>

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

int findOrderStatistic(std::vector<int>& arr, int k) {
    int left = 0, right = arr.size();
    
    while (true) {
        int mid = Partition(arr, left, right);

        if (mid == k) return arr[mid]; 

        else if (k < mid) right = mid;

        else left = mid + 1;
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
    std::cout << findOrderStatistic(vec, 4);

}

