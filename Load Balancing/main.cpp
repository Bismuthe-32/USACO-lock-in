#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);

    int N, B;
    cin >> N >> B;

    vector<pair<int,int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    int M = 10000000;

    for(int cow=0;cow<N;cow++){
        int candidate_a=cows[cow].first+1;
        

        for(int cow2=0;cow2<N;cow2++){
            int candidate_b=cows[cow2].second+1;
            int q1=0,q2=0,q3=0,q4=0;
            for(int all_cows=0;all_cows<N;all_cows++){
                int x=cows[all_cows].first;
                int y=cows[all_cows].second;

                if(x>candidate_a && y > candidate_b) q1++;
                else if(x<candidate_a && y > candidate_b) q2++;
                else if(x<candidate_a && y<candidate_b) q3++;
                else if(x>candidate_a && y<candidate_b) q4++;
            }
            M = min(max({q1,q2,q3,q4}),M);
        }
    }
    cout << M << '\n';
}