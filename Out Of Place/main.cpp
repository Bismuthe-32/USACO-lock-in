#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);

    int N; 
    cin >> N;

    vector<int> heights(N);
    vector<int> sorted_heights(N);
    vector<int> unlock_idx;

    for(int i=0;i<N;i++){
        cin >> heights[i];
        sorted_heights[i] = heights[i];
    }

    sort(sorted_heights.begin(), sorted_heights.end());

    for(int i=0;i<N;i++){
        if(sorted_heights[i] != heights[i]){
            unlock_idx.push_back(i);
        }
    }
    int cnt=0;
    for(int i=1;i<unlock_idx.size();i++){
        while(heights[unlock_idx[i-1]] > heights[unlock_idx[i]]){
            swap(heights[unlock_idx[i-1]], heights[unlock_idx[i]]);
            cnt++;
            i--;
        }
    }
    cout << cnt << '\n';
}
