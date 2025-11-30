#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);

    string A;
    string B;
    int N;cin>>N>>A>>B;

    bool isBlock=false;
    int flips=0;

    for(int i=0;i<N;i++){
        if(A[i]!=B[i]){
            if(!isBlock){
                isBlock=true;
                flips++;
            }
        } else {
            isBlock=false;
        }
    }
    cout << flips << '\n';
}