#include <iostream>
#include <vector>
#include <string>
#include <set> // add set

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> solns;
    
    int T; cin >> T;
    while(T--){
        int N,A,B; cin >> N >> A >> B;
        vector<string> grid(N, string(N, '.'));
        vector<string> bfore_grid(N, string(N, '.'));

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> grid[i][j];
            }
        }

        bool impossible=false;
        set<pair<int,int>> sources; // track unique "before" cells

        for(int i=N-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                if(grid[i][j]=='B'){
                    if(i-B < 0 || j-A < 0 || grid[i-B][j-A]=='W'){
                        impossible=true;
                        break;
                    }
                    sources.insert({i-B,j-A});
                    sources.insert({i,j});
                }
                if(grid[i][j]=='G'){
                    int dest_i = i+B, dest_j = j+A;
                    if(dest_i >= N || dest_j >= N || sources.count({dest_i,dest_j})==0){
                        sources.insert({i,j});
                    }
                }
            }
            if(impossible) break;
        }


        int cnt = impossible ? -1 : sources.size(); // count unique cells
        solns.push_back(cnt);
    }

    for(auto& soln : solns){
        cout << soln << '\n';
    }
}
