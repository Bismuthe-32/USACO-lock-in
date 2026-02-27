#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

struct Triple {
    int x, y, z;
    bool operator<(const Triple &other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    map<Triple, int> freq; // count identical triples
    for (int i = 0; i < K; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Triple t = {x-1, y-1, z-1}; // zero-index
        freq[t]++;
    }

    vector<pair<int,int>> masks; // {maskM, maskO} for each unique triple
    vector<int> counts;           // frequency of each triple
    for (auto &p : freq) {
        int maskM = 0, maskO = 0;
        maskM |= (1 << p.first.x);  // M at position x
        maskO |= (1 << p.first.y);  // O at y
        maskO |= (1 << p.first.z);  // O at z
        masks.push_back({maskM, maskO});
        counts.push_back(p.second);
    }

    int max_score = 0, num_boards = 0;
    int total_boards = 1 << N; // 2^N possible boards

    for (int board = 0; board < total_boards; board++) {
        int score = 0;
        for (int i = 0; i < masks.size(); i++) {
            int maskM = masks[i].first;
            int maskO = masks[i].second;
            if ((board & maskM) == maskM && ((~board) & maskO) == maskO) {
                score += counts[i];
            }
        }
        if (score > max_score) {
            max_score = score;
            num_boards = 1;
        } else if (score == max_score) {
            num_boards++;
        }
    }

    cout << max_score << " " << num_boards << "\n";
    return 0;
}
