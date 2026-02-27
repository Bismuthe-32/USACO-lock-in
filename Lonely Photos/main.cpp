#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;cin>>N;
    vector<int> Gs;
    vector<int> Hs;
    for(int i=0;i<N;i++){
        char c;cin>>c;
        if(c=='G'){
            Gs.push_back(i);
        }
        if(c=='H'){
            Hs.push_back(i);
        }
    }
    long long total_cow_photos=0LL;
    for (int i = 0; i < Hs.size(); i++) {
        int left_bound, right_bound;

        if (Hs.size() == 1) {
            left_bound = 0;
            right_bound = N - 1;
        }
        else if (i == 0) {
            left_bound = 0;
            right_bound = Hs[i + 1] - 1;
        }
        else if (i == Hs.size() - 1) {
            left_bound = Hs[i - 1] + 1;
            right_bound = N - 1;
        }
        else {
            left_bound = Hs[i - 1] + 1;
            right_bound = Hs[i + 1] - 1;
        }
        total_cow_photos += max(Hs[i] - left_bound - 1, 0);
        total_cow_photos += max(right_bound - Hs[i] - 1, 0);
        total_cow_photos += 1LL * (Hs[i] - left_bound) * (right_bound - Hs[i]);
    }

    for (int i = 0; i < Gs.size(); i++) {
        int left_bound, right_bound;

        if (Gs.size() == 1) {
            left_bound = 0;
            right_bound = N - 1;
        }
        else if (i == 0) {
            left_bound = 0;
            right_bound = Gs[i + 1] - 1;
        }
        else if (i == Gs.size() - 1) {
            left_bound = Gs[i - 1] + 1;
            right_bound = N - 1;
        }
        else {
            left_bound = Gs[i - 1] + 1;
            right_bound = Gs[i + 1] - 1;
        }

        total_cow_photos += max(Gs[i] - left_bound - 1, 0);
        total_cow_photos += max(right_bound - Gs[i] - 1, 0);
        total_cow_photos += 1LL * (Gs[i] - left_bound) * (right_bound - Gs[i]);
    }

    cout << total_cow_photos << '\n';
}