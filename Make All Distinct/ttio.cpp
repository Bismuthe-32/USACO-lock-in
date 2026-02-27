#include <bits/stdc++.h>
#include <iostream>




/**
 * We use remainders, numbers with different remainders when divided by K will never approach each other
 * group num by remainders 
 */


using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;cin>>T;

    while (T--) {
        ll N, K;cin>>N>>K;
        vector<ll> arr(N);
        for (ll i = 0; i < N; i++)cin >> arr[i];

        /**
         * a_i = K mod smth.    
         * K and -K are the same so abs K neutralizes it
         */


        ll jump = abs(K);
        // Group numbers by their remainder when divided by step
        unordered_map<ll, vector<ll>> remainders;
        for (ll a : arr) {
            ll r = (a % jump);
            remainders[r].push_back(a);
        }

        ll ops = 0;



        for (auto &r : remainders) {
            vector<ll> &r_arr = r.second;

            if (K > 0) sort(r_arr.begin(), r_arr.end());
            else sort(r_arr.begin(), r_arr.end(), greater<ll>());

            ll pre = r_arr[0];

            for (int i = 1; i < r_arr.size(); i++) {
                /**
                 * Nxt num must be at least step away from the previous number
                 */
                ll req = (K > 0) ? pre + jump : pre - jump;
                /**
                 * If current num is not at least step away from the previous num, move it to rqrd. 
                  else, we can keep it and update the previous to curr.
                 */
                if ((K > 0 && 
                    r_arr[i] < req) 
                    || 
                (K < 0 && 
                    r_arr[i] > req)
                ) {
                    ops += abs(req - r_arr[i]) / jump;
                    pre = req;
                } else {pre = r_arr[i];}
            }
        }

        cout << ops << '\n';
    }

    return 0;
}