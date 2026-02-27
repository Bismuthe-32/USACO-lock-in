#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;cin>>N;
    vector<int> a(N);
    vector<int> b(N);
    for(int i=0; i<N; i++) cin>>a[i];
    for(int i=0; i<N; i++) cin>>b[i];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    vector<int> fit(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        if(a[j]<=b[i]) fit[i]++;
        }
    }
    long long ans = 1;
    for(int i=0; i<N; i++){
        ans*=fit[i]-i;
    }
    cout<<ans;
}