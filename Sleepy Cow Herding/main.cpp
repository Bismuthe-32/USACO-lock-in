#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);

    int gap1 = a[1] - a[0];
    int gap2 = a[2] - a[1];

    // Minimum moves
    int min_moves;
    if(gap1 == 1 && gap2 == 1)
        min_moves = 0;
    else if(gap1 <= 2 || gap2 <= 2)
        min_moves = 1;
    else
        min_moves = 2;

    // Maximum moves
    int max_moves = max(gap1, gap2) - 1;

    cout << min_moves << "\n" << max_moves << "\n";

    return 0;
}
