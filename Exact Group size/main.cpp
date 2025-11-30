#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K; cin >> N >> K;
    vector<int> aVector(N);
    vector<int> bVector(N);

    for(int i=0;i<N;i++){
        cin >> aVector[i];
    }

    for(int i=0;i<N;i++){
        cin >> bVector[i];
    }

    bool running = false;
    bool found = false;

    for(auto& e : aVector){
        for(int i=0;i<N;i++){
            if(e+bVector[i]==K){
                found = true;
                cout << e << " " << bVector[i] << "\n";
                break;
            }
        }
        if(found==true){
            break;
        }
    }
}