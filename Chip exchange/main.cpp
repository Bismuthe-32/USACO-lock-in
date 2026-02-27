#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T;
    cin >> T;
    vector<long long> solns;


    while(T--) {
        ll A, B, cA, cB, fA;
        cin >> A >> B >> cA >> cB >> fA;
        ll q=(ll)ceil((double)(fA-A)/cA); //ops taken to initially reach at least fA
        ll n=(ll)floor((double)B/cB); // ops taken to not go below 0
        // we only add to b
        if(q<=n){ // if a reaches point before b, then no need to add anything
            solns.push_back(0LL);
            continue;
        }
        else{
            
            solns.push_back((q*cB)-B);
        }

    }
    for(auto& soln : solns){
        cout << soln << '\n';
    }
}
