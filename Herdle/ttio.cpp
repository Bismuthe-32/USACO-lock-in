#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> answer(3), guess(3);
    for (int i = 0; i < 3; i++) cin >> answer[i];
    for (int i = 0; i < 3; i++) cin >> guess[i];

    bool usedA[3][3] = {}, usedG[3][3] = {};
    int green = 0, yellow = 0;

    // Count greens
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (answer[i][j] == guess[i][j]) {
                green++;
                usedA[i][j] = usedG[i][j] = true;
            }
        }
    }

    // Count remaining letters
    int cntA[26] = {}, cntG[26] = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!usedA[i][j])
                cntA[answer[i][j] - 'A']++;
            if (!usedG[i][j])
                cntG[guess[i][j] - 'A']++;
        }
    }

    // Count yellows
    for (int c = 0; c < 26; c++) {
        yellow += min(cntA[c], cntG[c]);
    }

    cout << green << "\n" << yellow << "\n";
}
