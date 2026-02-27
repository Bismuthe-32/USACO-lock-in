#include <iostream>
#include <vector>

using namespace std;

int limitSeg[100];
int bessieSeg[100];

int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);

    int N,M;cin>>N>>M;
    int pos = 0;
    for(int i = 0; i < N; i++){
        int length, speed;
        cin >> length >> speed;
        for(int j = 0; j < length; j++){
            limitSeg[pos++] = speed;
        }
    }

    pos = 0;
    for(int i = 0; i < M; i++){
        int length, speed;
        cin >> length >> speed;
        for(int j = 0; j < length; j++){
            bessieSeg[pos++] = speed;
        }
    }
    
    int maxOver=0;
    for(int i=0;i<100;i++){
        maxOver=max(maxOver,bessieSeg[i]-limitSeg[i]);
    }

    cout << maxOver << '\n';
}