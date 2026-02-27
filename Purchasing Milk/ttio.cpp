#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    // Step 1: preprocess costs (larger packs are never worse)
    for (int i = 1; i < N; i++) a[i] = min(a[i], 2*a[i-1]);

    // Step 2: prefix-min array for overbuying
    vector<ll> best(N);
    best[0] = a[0];
    for (int i = 1; i < N; i++) best[i] = min(a[i], 2*best[i-1]);

    while (Q--) {
        ll x;
        cin >> x;

        ll ans = LLONG_MAX;  // minimal total cost
        ll cost = 0;         // running cost
        ll remaining = x;

        // Step 3: iterate from largest pack down
        for (int i = min(N-1.0,log2(remaining)+1); i >= 0; i--) {
            if(remaining<=0) break;
            ll pack = 1LL << i;
            ll take = remaining / pack;
            cost += take * a[i];
            remaining -= take * pack;

            // consider buying one extra pack of this size to cover leftover
            ans = min(ans, cost + (remaining > 0 ? best[i] : 0));
        }

        cout << ans << "\n";
    }
}
