#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    vector<int> solns(N+1, 0);
    for(int l = 0; l < N; l++) {
        for(int r = l; r < N; r++) {
            vector<int> new_A = A;
            reverse(new_A.begin() + l, new_A.begin() + r + 1);

            int checked = 0;
            for(int i = 0; i < N; i++) {
                if(new_A[i] == B[i]) checked++;
            }

            solns[checked]++;
        }
    }
    for(int c = 0; c <= N; c++) {
        cout << solns[c] << '\n';
    }
    
}
