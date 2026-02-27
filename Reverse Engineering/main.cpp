#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <vector>

using namespace std;

int grid[100][101] = {-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;cin>>T;
    while(T--){
        int N,M;cin>>N>>M;
        for(int m=0;m<M;m++){
            for(int n=0;n<N;n++){
                char c;cin>>c;
                c-='0';
                grid[m][n]=c;
            }
            cin>>grid[m][N];
        }
        vector<bool> alive(M, true);
        int remaining=M;

        bool possible = true;
        
        while(remaining>0){
            bool found = false;
            for(int n=0;n<N;n++){
                for(int v=0;v<=1;v++){
                    int output = -1;
                    bool ok=true;

                    for(int m=0;m<M;m++){
                        if(!alive[m] || grid[m][n] != v) continue;
                        if(output==-1) output=grid[m][N];
                        else if(output != grid[m][N]){
                            // output is inconsistent, the same output created two dfferent values, hence the value at grid[m][n] (v) is an inconsistent input
                            ok = false;
                        }
                    }
                    if(!ok || output == -1) continue;
                    // if ok true, that mean all values of v in column n is consistent with the output and must be removed

                    found = true; //consistent pair is found
                    // for all rows in column n, if the row is still alive AND is consistent, meaning that 
                    for(int m=0;m<M;m++){
                        if(alive[m] && grid[m][n]==v){
                            alive[m]=false;
                            remaining--;
                        }
                    }
                    break;
                }
                if(found) break;
            }
            // if no consistent row, then no reverse engineering has been found
            if(!found){
                possible=false;
                break;
            }
        }
        cout << (possible ? "OK" : "LIE") << '\n';
    }
}