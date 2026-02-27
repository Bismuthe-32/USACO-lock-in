#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // distinct_before[i] = number of distinct values in a[0..i-1]
    vector<int> distinct_before(N, 0);
    unordered_set<int> seen;

    for (int i = 1; i < N; i++) {
        seen.insert(a[i - 1]);
        distinct_before[i] = seen.size();
    }

    // store first two occurrences only
    unordered_map<int, pair<int,int>> pos;

    for (int i = 0; i < N; i++) {
        if (!pos.count(a[i])) {
            pos[a[i]] = {i, -1};
        } else if (pos[a[i]].second == -1) {
            pos[a[i]].second = i;
        }
    }

    long long answer = 0;

    for (auto &[val, p] : pos) {
        if (p.second != -1) { // appears at least twice
            answer += distinct_before[p.first];
        }
    }

    cout << answer << '\n';
    return 0;
}
