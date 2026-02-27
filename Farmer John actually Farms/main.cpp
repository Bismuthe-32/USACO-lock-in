#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

using namespace std;

int main(){
    ll T;cin>>T;
    vector<ll> solnList;

    while(T--){
        int N;cin>>N;
        vector<ll> H(N);
        vector<ll> A(N);
        vector<ll> T(N);
        vector<ll> sortVec(0,0);

        for(int i=0;i<N;i++){
            cin>>H[i];
        }
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>T[i];
        }

        int ts=0;
        sortVec=H;
        sort(sortVec.begin(),sortVec.end());
        bool answerNegative=true;
        while(ts<1000){
            bool found = true;
            for(int cow=0;cow<N;cow++){
                if((N-1-(find(sortVec.begin(),sortVec.end(),H[cow])-sortVec.begin()))!=T[cow]){
                    found=false;
                    break;
                }
            }
            if(found){
                solnList.push_back(ts);
                answerNegative=false;
                break;
            }
            ts++;
            for(int cow=0;cow<N;cow++){
                // Update height for each cow
                H[cow]+=A[cow];
            }
            sortVec=H;
            sort(sortVec.begin(),sortVec.end());
        }
        if(answerNegative){
            solnList.push_back(-1LL);
        }
    }
    for(auto& soln : solnList){
        cout << soln << '\n';
    }
}