#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);

    int N; cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));

    int min_total = 0; //Must visit D

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='D'){
                min_total++;
            }
        }
    }


    cout << min_total << '\n';

    int max_total = min_total; //May visit + min_total

    bool checkForF=true;


    int xDir[4] = {0,0,1,-1};
    int yDir[4] = {1,-1,0,0};

    vector<vector<double>> check_grid(N, vector<double>(N, 0.0));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(checkForF){
                if(grid[i][j]=='F'){
                    max_total++;
                    checkForF=false;
                }
            }
            if(grid[i][j]=='D'){
                for(int d=0;d<4;d++){
                    if(
                        0 <= i+xDir[d] && i+xDir[d] < N && 
                        0 <= j+yDir[d] && j+yDir[d] < N
                    ){ //If in bounds
                        check_grid[i+xDir[d]][j+yDir[d]]+=0.5;
                        if(check_grid[i+xDir[d]][j+yDir[d]]>=1){
                            max_total++;
                        }
                    }
                }
            }

        }
    }

    cout << max_total << '\n';
}