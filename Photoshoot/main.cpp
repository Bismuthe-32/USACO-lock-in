#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, K;cin>>N>>K;
    int M = N - K + 1;                     //possible top-left corners


    vector<vector<int>> sums(M+1, vector<int>(M+1, 0));
    vector<vector<int>> curr(N+1, vector<int>(N+1, 0));
    vector<int> solns;

    int max_sum = 0;
    int Q;cin>>Q;


    while (Q--) {
        int r,c,v;cin>>r>>c>>v;
        int delta = v-curr[r][c];
        curr[r][c]=v;
        int il=max(1,r-K+1);
        int ih=min(r, M);
        int jl=max(1, c-K+1);
        int jh=min(c, M);


        for (int i=il;i<=ih;i++) {
            for (int j=jl;j<=jh;j++) {
                sums[i][j] += delta;
                max_sum=max(max_sum,sums[i][j]);
            }
        }
        solns.push_back(max_sum);
    }
    for(auto& soln : solns){
        cout << soln << '\n';
    }
}