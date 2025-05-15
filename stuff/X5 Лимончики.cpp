#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
// WRONG
int main() {
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d;
    cin >> n;
    
    // Переводим n килограммов в четвертушки
    n *= 4;
    
    // Оптимизируем цену за каждый возможный вес
    // 0.5 кг дешевле: h vs 2*q
    h = min(h, 2 * q);
    // 1 кг дешевле: s vs 2*h vs 4*q
    s = min(s, min(2 * h, 4 * q));
    // 2 кг дешевле: d vs 2*s vs 4*h vs 8*q
    d = min(d, min(2 * s, min(4 * h, 8 * q)));
    
    ll result = 0;
    
    // Сначала берём максимум 2 кг блоков
    result += (n / 8) * d;
    n %= 8;
    
    // Потом берём максимум 1 кг блоков
    result += (n / 4) * s;
    n %= 4;
    
    // Потом максимум 0.5 кг блоков
    result += (n / 2) * h;
    n %= 2;
    
    // Остаток 0.25 кг 
    result += n * q;
    
    cout << result << endl;
    return 0;
}