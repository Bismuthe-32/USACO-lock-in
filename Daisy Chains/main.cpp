#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    vector<double> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i];

    vector<double> pSum(N);
    pSum[0] = arr[0];
    for(int i = 1; i < N; i++) pSum[i] = pSum[i-1] + arr[i];

    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            double sum = pSum[j] - (i > 0 ? pSum[i-1] : 0.0);
            double avg = sum / (j - i + 1);

            // Check if average exists in arr[i..j]
            bool found = false;
            for(int k = i; k <= j; k++) {
                if(fabs(arr[k] - avg) < 1e-9) {
                    found = true;
                    break;
                }
            }

            if(found) {
                count++;
            }
        }
    }

    cout << count << '\n';
}
