#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);

    int N;cin>>N;

    vector<pair<int,int>> shuffle_order;
    vector<int> cow_order_prev;
    vector<int> cow_order_next(N);

    for(int i=0;i<N;i++){
        int s; cin >> s;s-=1;
        shuffle_order.push_back({s,i});
    }

    for(int i=0;i<N;i++){
        int id; cin >> id;
        cow_order_prev.push_back(id);
    }

    sort(shuffle_order.begin(), shuffle_order.end());

    for(int i=0; i<3;i++){
        for(auto& [k, v] : shuffle_order){
            cow_order_next[v] = cow_order_prev[k];
        }
        cow_order_prev=cow_order_next;

    }

    for(auto& id : cow_order_next){
        cout << id << '\n';
    }
}