#include <iostream>
#include <vector>
using namespace std;

void set(vector<bool>& line, char g_or_l, int start){
    if(g_or_l=='G'){
        for(int i=start;i<=100;i++){
            if(line[i]==false){
            }
            line[i]=true;
        }
    }
    if(g_or_l=='L'){
        for(int i=start;i>=1;i--){
            line[i]=true;
        }
    }
}

int main(){
    vector<bool> line(101,false);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;cin>>N;

    int minI=0;

    for(int i=0;i<N;i++){
        char g_or_l;
        int start;
        cin >> g_or_l >> start;
        set(line, g_or_l,start);
    }
    
    for(auto point : line){
        
    }

    cout << minI << "\n";
}
