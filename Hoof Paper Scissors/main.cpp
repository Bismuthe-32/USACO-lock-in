#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// 0 = Hoof, 1 = Paper, 2 = Scissors
bool beats(int a, int b) {
    return (a == 0 && b == 2) ||  // Hoof beats Scissors
           (a == 2 && b == 1) ||  // Scissors beats Paper
           (a == 1 && b == 0);    // Paper beats Hoof
}

int main() {
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);

    int N;
    cin >> N;
    vector<pair<int, int>> games(N);
    for (int i = 0; i < N; i++) {
        cin >> games[i].first >> games[i].second;
        games[i].first--;   // make 0-indexed
        games[i].second--;
    }

    vector<int> perm = {0, 1, 2}; // possible mappings
    int best = 0;

    // Try all 3! = 6 mappings
    do {
        int wins = 0;
        for (auto [a, b] : games) {
            int a_gesture = perm[a];
            int b_gesture = perm[b];
            if (beats(a_gesture, b_gesture))
                wins++;
        }
        best = max(best, wins);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << best << "\n";
    return 0;
}
