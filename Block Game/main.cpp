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

    vector<pair<string,string>> wordPairs(N);

    vector<string> combs(N*2);

    for(int i=0;i<N;i++){
        cin>>wordPairs[i].first>>wordPairs[i].second;
    }
    int totalComb = 1 << N; // 2^N combinations
    vector<string> allCombs;

    for (int mask = 0; mask < totalComb; mask++) {
        string s = "";
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) 
                s += wordPairs[i].first; // choose first word
            else 
                s += wordPairs[i].second; // choose second word
        }
        allCombs.push_back(s);
    }

    int count;

    for(auto& comb : allCombs){
        for(char c = 'a';c<='z';c++){
            count=0;
            for(char part : comb){
                if(part==c){
                    count++;
                }
            }
            repeatList[c-'a']=max(repeatList[c-'a'],count);
        }
    }

    for(auto& i : repeatList){
        cout << i << '\n';
    }

    return 0;
}
