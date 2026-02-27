#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);

    int N=26;
    vector<pair<int,int>> startEndLoc(N,{-1,-1});
    for(int i=0;i<2*N;i++){
        char c;cin>>c;
        if(startEndLoc[(int)(c-'A')].first==-1){
            startEndLoc[(int)(c-'A')].first=i;
        }
        else{
            startEndLoc[(int)(c-'A')].second=i;
        }
    }

    int cp=0;

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            int x1 = startEndLoc[i].first,y1=startEndLoc[i].second;
            int x2 = startEndLoc[j].first,y2=startEndLoc[j].second;

            if(x1==x2 && y1==y2) continue;

            int intersection = max(0,
                min(y1,y2)-max(x1,x2)
            );
            if(intersection>0){
                if(intersection!=(y1-x1) && intersection!=(y2-x2)){
                    cp++;
                }
            }
        }
    }

    cout << cp << '\n';
}