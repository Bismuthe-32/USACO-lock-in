#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    // Step 1: convert string into clusters of consecutive 1s
    vector<int> groups;
    int cnt = 0;
    for (char c : s) {
        if (c == '1') {
            cnt++;
        } else {
            if (cnt > 0) groups.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt > 0) groups.push_back(cnt);

    // Step 2: compute min_days (max simulation days allowed)
    int min_days = N;  // large initial
    for (int i = 0; i < groups.size(); i++) {
        int v = groups[i];
        int days = (v - 1) / 2;  // middle cluster
        if ((i == 0 && s[0] == '1') || (i == groups.size() - 1 && s[N - 1] == '1')) {
            days = v - 1;  // edge cluster
        }
        min_days = min(min_days, days);
    }

    // Step 3: compute spread
    int spread = 1 + 2 * min_days;

    // Step 4: count minimum initial cows
    int total = 0;
    for (int v : groups) {
        total += (v + spread - 1) / spread;  // ceiling division
    }

    cout << total << '\n';
}
