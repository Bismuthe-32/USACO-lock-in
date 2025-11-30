#include <iostream>
#include <vector>
using namespace std;

int dirX[4] = {-1,1,0,0};
int dirY[4] = {0,0,-1,1};

void dp(int x, int y, int prevx, int prevy, int &c, int &C, int &R){
    if(x>C-1 || x<0 || y>R-1 || y<0){
        return;
    }
    if(prevx == x || prevy == y){
        return;
    }
    if(y < prevy+1){
        return;
    }
    if(x < prevx+1){
        return;
    }
    for(int i=0;i<4;i++){
        dp(x+dirX[i],y+dirY[i],x,y,++c,C,R);
    }
}

int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);

    int R, C, K;
    cin >> R >> C >> K;

    vector<vector<int>> grid(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int x=0,y=0;

    int c=0;
    dp(x,y,-1,-1,c,C,R);

    cout << c << '\n';
    return 0;
}