#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int64 T;
    cin >> N >> T;

    vector<pair<int64, int64>> deliveries(N);
    for (int i = 0; i < N; i++) {
        cin >> deliveries[i].first >> deliveries[i].second;
    }

    int64 cur = 0;       // current haybales
    int64 eaten = 0;    // total eaten
    int64 lastDay = 1;  // start from day 1

    for (auto &[d, b] : deliveries) {
        // Days before this delivery
        int64 gap = d - lastDay;
        int64 eatNow = min(cur, gap);
        eaten += eatNow;
        cur -= eatNow;

        // Delivery arrives
        cur += b;
        lastDay = d;
    }

    // After last delivery until day T
    int64 remainingDays = T - lastDay + 1;
    eaten += min(cur, remainingDays);

    cout << eaten << "\n";
    return 0;
}
