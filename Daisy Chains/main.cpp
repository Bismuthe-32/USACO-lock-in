#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) cin >> p[i];

    // Prefix sums
    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i-1] + p[i-1];
    }

    int count = 0;
    // Check all subarrays
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            int sum = prefix[j] - prefix[i-1];
            int len = j - i + 1;
            // Check if any flower has value equal to the average
            for (int k = i-1; k < j; ++k) {
                if (p[k] * len == sum) {
                    count++;
                    break; // Only count once per subarray
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
