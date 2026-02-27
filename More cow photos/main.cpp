#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    vector<int> solns;
    while (T--) {
        int N; cin >> N;
        vector<int> arr(N);
        for (int &x : arr) cin >> x;

        vector<int> freq(N + 1, 0);  // frequency array
        int mx = 0;

        for (int x : arr) {
            freq[x]++;
            mx = max(mx, x);
        }

        int pairs = 0;
        for (int h = 1; h < mx; h++) {  // only consider heights < maximum
            if (freq[h] >= 2) pairs++;
        }

        solns.push_back(2*pairs+1);
    }

    for(auto& soln : solns){
        cout << soln << '\n';
    }
}
