#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N,M;cin>>N>>M;

    vector<ll> cowHeights(N);

    for(int i=0;i<N;i++){
        cin>>cowHeights[i];
    }

    vector<ll> candyHeights(M);

    for(int i=0;i<M;i++){
        cin>>candyHeights[i];
    }

    ll lb,ub;

    for(ll i=0;i<M;i++){
        lb = 0;
        ub = candyHeights[i];
        for(ll j=0;j<N;j++){
            if(lb==ub) break;
            int change = min(ub-lb, max(0LL,cowHeights[j]-lb));
            cowHeights[j]+=change;
            lb+=change;
            lb=min(lb,ub);
        }
    }

    for(auto height : cowHeights){
        cout << height << '\n';
    }
}