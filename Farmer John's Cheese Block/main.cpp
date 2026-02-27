#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    static int countX[1000][1000];
    static int countY[1000][1000];
    static int countZ[1000][1000];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            countX[i][j] = countY[i][j] = countZ[i][j] = N;

    long long ans = 0;

    while (Q--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (--countX[y][z] == 0) ans++;
        if (--countY[x][z] == 0) ans++;
        if (--countZ[x][y] == 0) ans++;

        cout << ans << "\n";
    }
}
