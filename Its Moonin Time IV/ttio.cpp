#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string solve2(int N, string S) {
    string keys;
    bool flipped = false;
    for (int i = N - 1; i >= 0; --i) {
        char actual = S[i];
        if (flipped) actual = (actual == 'M' ? 'O' : 'M');

        if (actual == 'M') {
            keys.push_back('M');
        } else {
            keys.push_back('O');
            flipped = !flipped;
        }
    }
    reverse(keys.begin(), keys.end());
    return keys;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, ElseTypingCow;
    cin >> T >> ElseTypingCow;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        cout << "YES\n";
        if (ElseTypingCow == 1) {
            cout << solve2(N, S) << '\n';
        }
    }
}
