#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // for sort, find, next_permutation, abs
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    // All cows (fixed set)
    vector<string> cows = {
        "Beatrice", "Belinda", "Bella", "Bessie",
        "Betsy", "Blue", "Buttercup", "Sue"
    };

    int N;
    cin >> N;

    // Store adjacency constraints
    vector<pair<string,string>> constraints;
    for (int i = 0; i < N; i++) {
        string a, b, tmp;
        cin >> a;
        for (int j = 0; j < 4; j++) cin >> tmp; // skip "must be milked beside"
        cin >> b;
        constraints.push_back({a, b});
    }

    // Sort cows so permutations start in lexicographic order
    sort(cows.begin(), cows.end());

    do {
        bool valid = true;
        // Check all constraints
        for (auto &c : constraints) {
            string X = c.first, Y = c.second;
            int posX = find(cows.begin(), cows.end(), X) - cows.begin();
            int posY = find(cows.begin(), cows.end(), Y) - cows.begin();
            if (abs(posX - posY) != 1) {
                valid = false;
                break;
            }
        }
        if (valid) {
            for (auto &cow : cows) cout << cow << "\n";
            return 0; // first valid permutation is lexicographically smallest
        }
    } while (next_permutation(cows.begin(), cows.end()));

    return 0;
}
