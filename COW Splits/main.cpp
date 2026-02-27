#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string perms[3] = {"COW","OWC","WCO"};

void removesubseq(string& s, string& sub){
    s.erase(s.find(sub),s.find(sub)+sub.size());
}

int main(){
    int T;cin>>T;

    while(T--){
        string s;cin>>s;
        if(s.size()%2!=0){
            cout << -1 << '\n';
            continue;
        }
        for(auto& perm : perms){
            removesubseq(s,perm);
        }
        
    }
}