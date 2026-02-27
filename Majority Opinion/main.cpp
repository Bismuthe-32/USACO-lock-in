#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<vector<int>> all_answers;

    while(T--){
        int N;cin>>N;
        vector<int> hays(N);
        vector<bool> possible_hays(N+1);

        for(int i=0;i<N;i++){
            cin >> hays[i];
        }

        for(int i=0;i<N-1;i++){
            if(hays[i]==hays[i+1] || (i < N-2 && hays[i]==hays[i+2])){
                possible_hays[hays[i]]=1;
            }
        }
        vector<int> valid;
        for(int i=1;i<N+1;i++){
            if(possible_hays[i]){
                valid.push_back(i);
            }
        }
        if(valid.empty()){
            valid.push_back(-1);
        }
        all_answers.push_back(valid);
    }
    for(auto& answer : all_answers){
        for(int i=0;i<answer.size();i++){
            cout << answer[i];
            if(i!=answer.size()-1){
                cout << " ";
            }
        }
        cout << '\n';
    }
}
