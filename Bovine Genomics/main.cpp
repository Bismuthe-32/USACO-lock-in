#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);

    int N, M;
    cin >> N >> M;

    vector<string> spotty(N), plain(N);
    for (int i = 0; i < N; i++) cin >> spotty[i];
    for (int i = 0; i < N; i++) cin >> plain[i];

    int answer = 0;

    // Check each column
    for (int col = 0; col < M; col++) {
        bool intersection_exists = false; //If intersection does not exist, then increase count
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(spotty[i][col]==plain[j][col]){
                    intersection_exists=true;
                }
            }
        }
        if(!intersection_exists)answer++;
    }
    cout<<answer<<'\n';
}
