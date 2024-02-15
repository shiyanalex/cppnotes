#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// https://contest.yandex.ru/contest/51022/problems/

int calculateDays(int year, int month, int day) {
    int days = (year - 1) * 365;
    vector<int> dinm = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < month-1; ++i) {
        days += dinm[i];
    }

    days += day - 1;
    return days;
}

ll calculateSeconds(int y, int m, int d, int h, int min, int s) {
    ll days = calculateDays(y, m, d);
    return days*86400 + h*3600 + min*60 + s;
}

int main() {
    int year1,month1,day1,hour1,min1,sec1;
    int year2,month2,day2,hour2,min2,sec2;
    cin >> year1 >> month1 >> day1 >> hour1 >> min1 >> sec1;
    cin >> year2 >> month2 >> day2 >> hour2 >> min2 >> sec2;

    ll start = calculateSeconds(year1,month1,day1,hour1,min1,sec1);
    ll finish = calculateSeconds(year2,month2,day2,hour2,min2,sec2);
    ll diff = finish - start;
    cout << diff/86400 << " " << diff%86400;
}

