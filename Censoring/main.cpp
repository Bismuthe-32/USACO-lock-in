#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int isTinS(string t, string s){
    int length = t.size();
    for (int i = 0; i + length <= s.size(); i++){
        if (s.substr(i, length) == t){
            return i;
        }
    }
    return -1;
}

int main(){
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);

    string article; cin >> article;
    string censor; cin >> censor;

    string result;
    for (char c : article) {
        result.push_back(c);
        if (result.size() >= censor.size() &&
            result.substr(result.size() - censor.size()) == censor) {
            result.erase(result.size() - censor.size());
        }
    }
    cout << result << '\n';
}
