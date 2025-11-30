#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);

    int N, K; cin >> N >> K;

    vector<string> words(N);

    for(int i=0;i<N;i++){
        cin >> words[i];
    }
    int currentLength=0;
    for(int i=0;i<N;i++){
        if(currentLength+words[i].size() > K){
            cout << '\n';
            currentLength=0;
        }
        if(currentLength > 0) cout << " ";
        cout << words[i];
        currentLength+=words[i].size();
    }
}