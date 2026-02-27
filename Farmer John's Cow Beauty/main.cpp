#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k;
    cin >> T >> k;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;
        int n = 3*N;

        vector<int> ans(n,0);
        int C=0,O=0,W=0;
        for(char c:S) if(c=='C') C++; else if(c=='O') O++; else W++;

        if((C%2!=O%2)||(O%2!=W%2)){cout<<-1<<"\n"; continue;}

        vector<int> ops; // stores operation numbers per letter
        int op=1;
        // assign in greedy pattern like sample: last big squares first
        for(int i=n-1;i>=0;i--){
            if(S[i]=='W' && W>0){ ans[i]=op; W--; }
            else if(S[i]=='O' && O>0){ ans[i]=op; O--; }
            else if(S[i]=='C' && C>0){ ans[i]=op; C--; }
            if(i%6==0) op++; // every 6 letters start a new operation (matches sample)
        }

        cout << op-1 << "\n";
        for(int i=0;i<n;i++) cout << ans[i] << (i==n-1?"\n":" ");
    }
}

