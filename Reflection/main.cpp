#include <bits/stdc++.h>
using namespace std;

int N, U;
vector<string> grid;
long long total_cost = 0;

int orbit_cost(int i, int j) {
    int cnt = 0;
    cnt += grid[i][j] == '#';
    cnt += grid[i][N-1-j] == '#';
    cnt += grid[N-1-i][j] == '#';
    cnt += grid[N-1-i][N-1-j] == '#';
    return min(cnt, 4 - cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> U;
    grid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    // Initial total cost
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            total_cost += orbit_cost(i, j);
        }
    }

    // Output initial answer
    cout << total_cost << '\n';

    while (U--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        int i = min(r, N-1-r);
        int j = min(c, N-1-c);

        // Remove old orbit cost
        total_cost -= orbit_cost(i, j);

        // Toggle cell
        grid[r][c] = (grid[r][c] == '#') ? '.' : '#';

        // Add new orbit cost
        total_cost += orbit_cost(i, j);

        cout << total_cost << '\n';
    }
}
