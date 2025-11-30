#include <iostream>
#include <vector>

using namespace std;

bool used[4] = {false};
int curr = 0;
vector<int> perms;

void dfs(int idx=0){
    if(idx==3){
        perms.push_back(curr);
        return;
    }

    for(int i=1;i<=3;i++){
        if(used[i]) continue;
        
        used[i]=true;  // Choice
        curr=curr*10+i; // Choice


        dfs(idx+1); // Recurse
        curr = (curr-i) / 10; // Undo choice
        used[i] = false; // Undo Choice

    }
}

int main(){
    dfs();

    for(auto& perm : perms){
        cout << perm << '\n';
    }
}