#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    int N,M,K;cin>>N>>M>>K;

    vector<int> order(N);
    vector<int> hierarchy(M);
    vector<bool> filled(N);


    vector<int> cowids(N);
    for(int i=1;i<=N;i++){
        cowids[i-1]=i;
    }
    map<int,int> fixed;

    for(int i=0;i<M;i++){
        cin >> hierarchy[i];
    }
    for(int i=0;i<K;i++){
        int id;int idx;
        cin >> id >> idx;
        fixed[id]=--idx;
    }

    for(auto& pair : fixed){
        int id = pair.first; int idx = pair.second;
        order[idx]=id;
        filled[idx]=true;
    }

    int filled_idx=M-1;
    for(int i=0;i<N;i++){
        if(filled[i]==false){
            if(filled_idx>=0){
                for(int j=0;j<N;j++){
                    if(order[j]==hierarchy[filled_idx]){
                        i=j;
                        break;
                    }
                }
                order[N-1-i]=hierarchy[filled_idx];
                filled[N-1-i]=false;
                filled_idx--;
            }
        }
    }

    for(int i=0;i<N;i++){
        if(filled[i]==true){
            cout << order[i];
        }
        else {
            cout << " _ ";
        }
    }
    




}