#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define pii pair<int,int>

int dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);

    int N;
    cin >> N;
    vector<pii> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    // compute total distance
    int total = 0;
    for (int i = 1; i < N; i++) {
        total += dist(pts[i-1], pts[i]);
    }

    int bestSave = 0;
    for (int i = 1; i < N-1; i++) {
        int save = dist(pts[i-1], pts[i]) + dist(pts[i], pts[i+1]) - dist(pts[i-1], pts[i+1]);
        bestSave = max(bestSave, save);
    }

    cout << total - bestSave << "\n";
    return 0;
}
