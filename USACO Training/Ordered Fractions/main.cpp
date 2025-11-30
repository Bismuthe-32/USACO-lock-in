/*
ID: aditya_10
PROG: frac1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);

    int N;
    cin >> N;

    vector<pair<int,int>> fractions;

    for (int denom = 1; denom <= N; denom++) {
        for (int num = 0; num <= denom; num++) {
            if (gcd(num, denom) == 1) {
                fractions.push_back({num, denom});
            }
        }
    }

    sort(fractions.begin(), fractions.end(), [](auto &a, auto &b) {
        // Compare a.first/a.second with b.first/b.second
        return (long long)a.first * b.second < (long long)b.first * a.second;
    });

    for (auto &f : fractions) {
        cout << f.first << "/" << f.second << "\n";
    }

    return 0;
}
