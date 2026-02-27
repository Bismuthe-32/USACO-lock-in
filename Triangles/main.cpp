#include <bits/stdc++.h>


using namespace std;

int main(){
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);

    int N;cin>>N;
    vector<pair<int,int>> coords(N);

    for(int i=0;i<N;i++){
        cin>>coords[i].first>>coords[i].second;
    }

    bool vSide = false;
    bool hSide = false;

    int area2 = 0;

    for(int i=0;i<N;i++){ //for every point
        for(int j=0;j<N;j++){ //find all points with the same y (parallel to the x axis)
            if(coords[i].second==coords[j].second){
                for(int k=0;k<N;k++){ // find all points with the same x (parallel to the same x axis)
                    if(coords[i].first==coords[k].first){
                        area2=max(abs(coords[i].first-coords[j].first)*abs(coords[i].second-coords[k].second),area2);
                    }
                }
            }
        }
    }

    cout << area2 << '\n';
}