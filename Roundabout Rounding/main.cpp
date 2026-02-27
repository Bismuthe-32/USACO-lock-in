#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int generate_lb(int b /*10^b - 10^(b+1) is limit*/){
    if(b==0 || b==-1) return -1;
    int num=0;
    while(b--){
        num+=4;
        num*=10;
    }
    num+=5;
    return num;
}

int generate_ub(int b /*10^b - 10^(b+1) is limit*/){
    if(b==0 || b==-1) return -1;
    int num=4;
    while(b--){
        num*=10;
        num+=9;
    }
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<long long> solns;
    int T;cin>>T;
    while(T--){
        long long n;cin>>n;
        long long count=0LL;
        long long i=1;
        long long lb=generate_lb(i);
        long long ub=generate_ub(i);
        while(lb <= n){
            int high = min(ub, n);
            count += high - lb + 1;
            i++;
            lb = generate_lb(i);
            ub = generate_ub(i);
        }
        if(lb <= n && n <= ub) {
            count += n-lb+1;
        }
        solns.push_back(count);
    }

    for(auto& soln : solns){
        cout << soln << '\n';
    }
}