#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
/*  Вы пишете приложение для покупки товаров. В данном приложении можно переходить на страницу каждого товара.
    Пользователь при выборе может просматривать разные товары. Для удобства пользователя необходимо отдельно отображать
    список товаров согласно истории их просмотра, чтобы пользователь мог вернуться к товарам, которые ранее
    просматривал.
    N колво товаров, N пар ID и название товара. Т колво просмотров товара и IDшники просмотренных товаров.
    Необходимо вывести в N строках названия товаров согласно истории их просмотра, чтобы просмотренные недавно были в начале.
    Если какие-то товары не были просмотрены, выводить их не надо.
*/
using namespace std;

string solve(const vector<vector<string>>& products, vector<int>& views) {
    std::reverse(views.begin(), views.end());
    string ans;
    map<int, string> mapper;
    for (auto x: views) {
        if (mapper.contains(x));
        else {
            for (int i = 0; i < products.size(); ++i) {
                if (stoi(products[i][0]) == x) {
                    mapper[x] = products[i][1];
                    ans += products[i][1];
                    ans += "\n";
                    break;
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n;
    vector<vector<string>> products(n, vector<string>(2));
    for (int i = 0; i < n; i++) {
        cin >> products[i][0] >> products[i][1];
    }
    cin >> t;
    vector<int> views(t);
    for (int i = 0; i < t; i++) {
        cin >> views[i];
    }
    cout << solve(products, views) << "\n";
}

