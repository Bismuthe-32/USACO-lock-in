#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;cin >> T;
    while(T--){
        int N, M;cin >> N >> M;
        string t;cin >> t;
        vector<string> s(N);
        for(int i = 0; i < N; i++) cin >> s[i];
        vector<tuple<int,int,int,int>> ops;
        for(int i = 0; i < M; i++){if(s[0][i] == t[i]) continue;
            bool found = false;
            for(int j = i+1; j < M; j++){
                if(s[0][j] == t[i]){

                    ops.push_back({1, 1, i+1, j+1});
                    swap(s[0][i], s[0][j]);
                    found = true;
                    break;
                }
            }
            if(found) continue;
            for(int k = 1; k < N && !found; k++){
                for(int j = 0; j < M && !found; j++){
                    if(s[k][j] == t[i]){

                        if(j != i){

                            ops.push_back({1, k+1, i+1, j+1});
                            swap(s[k][i], s[k][j]);
                        }
                        ops.push_back({2, 1, k+1, i+1});
                        swap(s[0][i], s[k][i]);
                        found = true;
                    }
                }
            }
        }
        
        cout << ops.size() << "\n";
        for(auto& [type, a, b, c] : ops){
            cout << type << " " << a << " " << b << " " << c << "\n";
        }
    }
    return 0;
}