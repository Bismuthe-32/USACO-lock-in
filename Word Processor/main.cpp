#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    int N,K;cin>>N>>K;

    vector<string> words(N);

    for(int i=0;i<N;i++) cin >> words[i];

    int i=0;
    int lineLength=0;
    while(i<N){
        if(lineLength+words[i].length() <= K){
            if(lineLength > 0){
                cout << " ";
            }
            cout << words[i];
            lineLength+=words[i].length();
            i++;
        }
        else {
            cout << '\n';
            lineLength=0;
        }
    }
}