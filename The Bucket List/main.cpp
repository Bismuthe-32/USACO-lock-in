#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int S[101], B[101], T[101];

int avail_buckets[1000];
int used_buckets[];



int main(){
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);

    int N;cin>>N;

    for(int i=1;i<=N;i++){
        cin>>S[i]>>T[i]>>B[i];
    }
    int max_bucket=0;
    int current=0;
    for(int t=1;t<=1000;t++){
        current=0;
        for(int i=1;i<=N;i++){
            if(S[i]<=t && t<=T[i]){
                current+=B[i];
            }
        }
        max_bucket=max(max_bucket,current);
    }

    cout << max_bucket << '\n';
}