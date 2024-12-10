#include <iostream>
#include <vector>
#include <map>
/*
    В приложении Тинькофф отображаются предложения с кэшбэком от партнеров. Партнеров и предложений от них много. 
    Пользователи просматривают предложения, и для целей аналитиков необходимо вывести все предложения, отсортированные
    в порядке их просмотров от большего к меньшему.
    В первой строке идут целые неотрицательные числа N (1 < N < 10^5) и T (1 < T < 10^7) — количество предложений от партнеров
    и общее количество просмотров. Предложения имеют ID от 1 до N. На второй строке идут T целых чисел — ID предложений
    в порядке их просмотров пользователями.
    Вывести ID и колво просмотров. Пары чисел должны быть отсортированы в порядке количества просмотров от большего к меньшему.
*/

using namespace std;

void printDescendingOrder(map<int, int>& mp){
    vector<pair<int, int>> tempVec;

    for(auto &x : mp)
       tempVec.push_back({ x.first , x.second });

    sort(tempVec.rbegin(), tempVec.rend());

    for(auto &y : tempVec)
      cout << y.first << " " << y.second << "\n";
}

void solve(const vector<int>& views, int n, int t) {
    map<int, int> mapper;
    for (auto x: views) {
        ++mapper[x];
    }
    //for (auto x: mapper) cout << x.first << " " << x.second << "\n";
    printDescendingOrder(mapper);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> views(t);
    for (int i = 0; i < t; i++) {
        cin >> views[i];
    }
    solve(views, n, t);
}

