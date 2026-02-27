#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long dp[50][50][2][4]; // [row][col][last_dir][turns]
string grid[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> solns;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; i++) cin >> grid[i];

        memset(dp, 0, sizeof(dp));

        // Initialize first moves from (0,0)
        if (N > 1 && grid[0][1] == '.') dp[0][1][0][0] = 1; // right
        if (N > 1 && grid[1][0] == '.') dp[1][0][1][0] = 1; // down

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 'H') continue;

                for (int dir = 0; dir < 2; dir++) { // 0 = right, 1 = down
                    for (int turns = 0; turns <= K; turns++) {
                        long long ways = dp[r][c][dir][turns];
                        if (ways == 0) continue;

                        // Move right
                        if (c + 1 < N && grid[r][c + 1] == '.') {
                            int new_turns = turns + (dir != 0);
                            if (new_turns <= K)
                                dp[r][c + 1][0][new_turns] += ways;
                        }

                        // Move down
                        if (r + 1 < N && grid[r + 1][c] == '.') {
                            int new_turns = turns + (dir != 1);
                            if (new_turns <= K)
                                dp[r + 1][c][1][new_turns] += ways;
                        }
                    }
                }
            }
        }

        // Sum all valid ways to reach bottom-right
        long long ans = 0;
        for (int dir = 0; dir < 2; dir++)
            for (int turns = 0; turns <= K; turns++)
                ans += dp[N - 1][N - 1][dir][turns];

        solns.push_back(ans);
    }

    for(auto& soln : solns){
        cout << soln << '\n';
    }

    return 0;
}
