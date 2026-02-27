#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (int &w : p) cin >> w;

    sort(p.begin(), p.end());

    int i = 0, j = n - 1;
    int gondolas = 0;

    while (i <= j) {
        // Try to pair the lightest and heaviest child
        if (p[i] + p[j] <= x) {
            i++;    // the lightest is used
        }
        // heaviest is always used
        j--;
        gondolas++;
    }

    cout << gondolas << "\n";
}
