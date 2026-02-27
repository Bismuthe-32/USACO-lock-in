#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> repeatList(26, 0); // final letter counts

    for(int i=0;i<N;i++){
        int countA[26]={0};
        int countB[26]={0};

        string a,b;cin>>a>>b;

        for(char c : a){
            countA[c-'a']++;
        } 
        for(char c : b){
            countB[c-'a']++;
        }

        for(int i=0;i<26;i++){
            repeatList[i]+=max(countA[i],countB[i]);
        }
    }

    for(auto& count : repeatList){
        cout << count << '\n';
    }

}
