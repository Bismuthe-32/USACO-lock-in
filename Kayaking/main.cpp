#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> w(2*n);
    for (int i = 0; i < 2*n; ++i) cin >> w[i];
    sort(w.begin(), w.end());

    int best = INT_MAX;

    for (int i = 0; i < 2*n; ++i) {
        for (int j = i+1; j < 2*n; ++j) {
            // build the remaining list excluding i and j
            vector<int> rem;
            rem.reserve(2*n - 2);
            for (int k = 0; k < 2*n; ++k) {
                if (k == i || k == j) continue;
                rem.push_back(w[k]);
            }
            // pair neighbors
            int cur = 0;
            for (int t = 0; t < (int)rem.size(); t += 2) {
                cur += rem[t+1] - rem[t]; // rem is sorted
            }
            best = min(best, cur);
        }
    }

    cout << best << "\n";
    return 0;
}
