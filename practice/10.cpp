#include <iostream>
#include <vector>

struct IsGreater {
    bool operator()(int x, int y) {
        
    }
};

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void quick (std::vector<int>& v) {
    auto it1 = v.begin();
    auto it2 = v.end() - 1;
    int x = 5;
    if (*it1 <= x) ++it1;
    else {
        while (*it2 >= x) --it2;
        std::swap(*it1, *it2);
        ++it1;
        --it2;
    }
    if (it1 == it2) return;
}

void mymerge(std::vector<int>& v, std::vector<int>& vv, std::vector<int>& m) {
    m.reserve(v.size() + vv.size());
    m = v;
    for (int x : vv) m.push_back(x);
    quickSort(m);
    //std::sort(m.begin(), m.end(), IsGreater());
    //std::sort(m.begin(), m.end());

}


int main() {

    std::vector<int> v1{1,2,5,9};
    std::vector<int> v2{3,4,5,6,9};
    
    std::vector<int> dst;
    std::vector<int> m;

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));
    mymerge(v1, v2, m);
    for (int x : m) std::cout << x;
    std::cout << "\ncorrect one: \n";
    for (int x : dst) std::cout << x;

}

