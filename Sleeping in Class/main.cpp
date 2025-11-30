#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; 
    cin >> T;
    while (T--) {
        int N; 
        cin >> N;
        vector<int> arr(N);
        int total = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            total += arr[i];
        }

        if (total == 0) {
            cout << 0 << "\n";
            continue;
        }

        int answer = N; // worst case: N merges (actually N-1 but safe)
        for (int d = 1; d <= N; d++) {
            if (total % d != 0) continue;
            int target = total / d;

            int sum = 0;
            bool ok = true;
            for (int x : arr) {
                sum += x;
                if (sum > target) { ok = false; break; }
                if (sum == target) sum = 0;
            }
            if (ok && sum == 0) {
                // d groups → remaining lectures = d
                // merges required = N - d
                answer = min(answer, N - d);
            }
        }
        cout << answer << '\n';
    }
}
