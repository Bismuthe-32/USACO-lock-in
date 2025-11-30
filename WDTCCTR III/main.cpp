#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int arrival;
    int duration;
};

// Comparator to sort cows by arrival time
bool cmp(const Cow &a, const Cow &b) {
    return a.arrival < b.arrival;
}

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int N;
    cin >> N;
    vector<Cow> cows(N);

    for (int i = 0; i < N; i++) {
        cin >> cows[i].arrival >> cows[i].duration;
    }

    // Sort cows by arrival time
    sort(cows.begin(), cows.end(), cmp);

    int current_time = 0;
    for (int i = 0; i < N; i++) {
        // Cow starts when she arrives or when the gate is free, whichever is later
        current_time = max(current_time, cows[i].arrival);
        // Cow finishes after her duration
        current_time += cows[i].duration;
    }

    cout << current_time << endl;

    return 0;
}
