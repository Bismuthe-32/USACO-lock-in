#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> perms;

void dfs(int idx,int n, string &current){
    if(idx==n){
        perms.push_back(current);
        return ;
    }

    current.push_back('A'); // Action
    dfs(idx+1,n,current); // push down tree w/ action
    current.pop_back(); // Backtrack action

    current.push_back('B');
    dfs(idx+1,n,current);
    current.pop_back();

}

int main(){
    string current = "";
    dfs(0,3,current);

    for(auto& perm : perms){
        cout << perm << '\n';
    }
}