#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);

    int N, M;
    cin >> N >> M;

    vector<string> spotty(N), plain(N);
    for (int i = 0; i < N; i++) cin >> spotty[i];
    for (int i = 0; i < N; i++) cin >> plain[i];

    int answer = 0;

    // Check each column
    for (int col = 0; col < M; col++) {
        bool ok = true;

        // Collect characters in sets
        unordered_set<char> S, P;
        for (int i = 0; i < N; i++) {
            S.insert(spotty[i][col]);
            P.insert(plain[i][col]);
        }

        // Check intersection
        for (char c : S) {
            if (P.count(c)) {
                ok = false;
                break;
            }
        }

        if (ok) answer++;
    }

    cout << answer << "\n";
    return 0;
}
