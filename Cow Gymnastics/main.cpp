#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);

    int K, N;                 // FIX 1: correct order
    cin >> K >> N;

    vector<vector<int>> ranks;

    for(int i = 0; i < K; i++){
        vector<int> rank_for_k;
        for(int j = 0; j < N; j++){
            int l; 
            cin >> l;
            rank_for_k.push_back(l);
        }
        ranks.push_back(rank_for_k);
    }

    int cnt = 0;

    // FIX 2: loop over cow labels (1..N), not indices (0..N-1)
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if (i == j) continue;   // FIX 3: distinct cows only

            bool consistent = true;

            for(int session = 0; session < K; session++){
                vector<int>& session_ranks = ranks[session];

                int i_pos = -1, j_pos = -1;  // FIX 4: initialize

                for(int k = 0; k < N; k++){
                    if (session_ranks[k] == i) i_pos = k;
                    if (session_ranks[k] == j) j_pos = k;
                }

                if (i_pos > j_pos) {
                    consistent = false;
                    break;          // FIX 5: early exit
                }
            }

            if (consistent) cnt++;
        }
    }

    cout << cnt << '\n';
}
