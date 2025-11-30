#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, F;
    string s;
    cin >> N >> F >> s;

    // Count map: moo string -> frequency
    unordered_map<string,int> baseCount;

    auto addIfMoo = [&](const string &t, unordered_map<string,int> &cnt){
        if(t[0] != t[1] && t[1] == t[2])
            cnt[t]++;
    };

    // Step 1: original counts
    for(int i=0;i+2<N;i++){
        string sub = s.substr(i,3);
        addIfMoo(sub, baseCount);
    }

    // Copy base counts for reference
    unordered_map<string,int> bestCount = baseCount;

    // Step 2: try one corruption
    for(int pos=0; pos<N; pos++){
        char orig = s[pos];
        for(char c='a'; c<='z'; c++){
            if(c == orig) continue;

            // Temporary counts start from base
            auto tempCount = baseCount;

            // Substrings affected: starts at pos-2, pos-1, pos
            for(int d=-2; d<=0; d++){
                int i = pos + d;
                if(i < 0 || i+2 >= N) continue;

                string oldSub = s.substr(i,3);
                // remove old contribution
                if(oldSub[0] != oldSub[1] && oldSub[1] == oldSub[2]){
                    tempCount[oldSub]--;
                }

                // create new substring with modified character
                string newSub = oldSub;
                newSub[pos - i] = c;

                addIfMoo(newSub, tempCount);
            }

            // Merge into bestCount (we just need to know max frequencies across scenarios)
            for(auto &kv : tempCount){
                if(kv.second >= F)
                    bestCount[kv.first] = max(bestCount[kv.first], kv.second);
            }
        }
    }

    // Step 3: collect all moos with frequency >= F
    vector<string> result;
    for(auto &kv : bestCount){
        if(kv.second >= F) result.push_back(kv.first);
    }
    sort(result.begin(), result.end());

    // Step 4: output
    cout << result.size() << "\n";
    for(auto &moo : result){
        cout << moo << "\n";
    }
    return 0;
}
