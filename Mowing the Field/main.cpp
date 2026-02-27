#include <iostream>
#include <algorithm>

using namespace std;

bool grid[2001][2001] = {false};
int grid_num[2001][2001] = {0};

int main(){
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);

    int N;cin>>N;

    int sx = 1000, sy=1000;

    int x = 1<<20;
    int t=1;

    for(int i=0;i<N;i++){
        char D;int S;
        cin>>D>>S;

        for(int j=0;j<S;j++){
            if(D=='N'){
                sy++;
            }
            else if(D=='S'){
                sy--;
            }
            else if(D=='E'){
                sx++;
            }
            else if(D=='W'){
                sx--;
            }
            if(grid[sy][sx]==true){
                x=min(t-grid_num[sy][sx],x);
            }
            grid[sy][sx]=true;
            grid_num[sy][sx]=t;
            t++;
        }
    }
    if(x==1<<20){
        x=-1;
    }
    cout << x << '\n';
}