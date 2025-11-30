#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> arr(N);

    int sum = 0;

    for(int i=0;i<N;i++){
        int k;
        cin >> k;
        sum+=k;
        arr[i]=k;
    }

    auto maxArr = max_element(arr.begin(), arr.end());

    for(int i=*maxArr; i<=sum;i++){
        if(sum%i == 0){
            
        }
    }

}