#include <bits/stdc++.h>
using namespace std;

int n, vx[50001], vy[50001];

int main()
{
    ifstream cin("reduce.in");
    ofstream cout("reduce.out");

    vector<int> x, y;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> vx[i] >> vy[i];
        x.insert(vx[i]);
        y.insert(vy[i]);
    }

    int ans = 2000000001;

    for(int i = 1; i <= n; i++)
    {
        x.erase(x.lower_bound(vx[i]));
        y.erase(y.lower_bound(vy[i]));

        int minx = *x.begin();
        int miny = *y.begin();
        int maxx = *x.rbegin();
        int maxy = *y.rbegin();

        ans = min(ans, (maxy-miny) * (maxx-minx));

        x.insert(vx[i]);
        y.insert(vy[i]);
    }

    cout << ans;
    return 0;
}