#include <iostream>
#include <queue>
using namespace std;

string grid[10];
int distance_grid[10][10];
bool used[10][10] = {false};

queue<pair<int,int>> coords;

int main(){
    freopen("buckets.in","r",stdin);
    freopen("buckets.out","w",stdout);

    int startX,startY;

    for(int i=0;i<10;i++){
        cin>>grid[i];
        for(int j=0;j<10;j++){
            if(grid[i][j]=='L'){
                startY=i;startX=j;
                distance_grid[i][j]=0;
            }
        }
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    coords.push({startX,startY});
    bool found=false;
    while(!coords.empty()){
        pair<int,int> coord = coords.front();
        coords.pop();
        int x=coord.first;
        int y=coord.second;

        for(int i=0;i<4;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(newX < 0 || 9 < newX ||
                newY < 0 || 9 < newY || used[newY][newX] || grid[newY][newX]=='R') continue;

            distance_grid[newY][newX]=distance_grid[y][x]+1;
            if(grid[newY][newX]=='B'){
                cout << distance_grid[newY][newX]-1 << '\n';
                found=true;
                break;
            }
            used[newY][newX]=true;
            coords.push({newX,newY});
        }
        if(found){
            break;
        }
    }
}