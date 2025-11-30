#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll formula(ll x1, ll x2, ll y1, ll y2){
    return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    for (int i = 0; i < N; i++) cin >> y[i];

    ll maxDist = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll dist = formula(x[i], x[j], y[i], y[j]);
            maxDist = max(maxDist, dist);
        }
    }

    cout << maxDist << "\n";
}
