#include <iostream>

using namespace std;

vector<vector<char>> rconstrd_painting(vector<vector<char>>& section, int q) {
    int n = section.size();
    int N = 2 * n;

    vector<vector<char>> painting(N, vector<char>(N));

    // ---------------------------------------------
    // 1. PLACE THE GIVEN QUADRANT
    // ---------------------------------------------
    if (q == 1) {                 // top-right
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                painting[i][n + j] = section[i][j];
    }
    else if (q == 2) {            // top-left
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                painting[i][j] = section[i][j];
    }
    else if (q == 3) {            // bottom-left
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                painting[n + i][j] = section[i][j];
    }
    else if (q == 4) {            // bottom-right
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                painting[n + i][n + j] = section[i][j];
    }

    // ---------------------------------------------
    // 2. MIRROR ACROSS Y AXIS (horizontal flip)
    //    This fills the left half from the right,
    //    OR the right half from the left.
    // ---------------------------------------------
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            char right = painting[i][N - 1 - j];
            char left = painting[i][j];

            if (right != 0) painting[i][j] = right;
            else if (left != 0) painting[i][N - 1 - j] = left;
        }
    }

    // ---------------------------------------------
    // 3. MIRROR ACROSS X AXIS (vertical flip)
    //    This fills the bottom half from the top,
    //    OR the top half from the bottom.
    // ---------------------------------------------
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            char bottom = painting[N - 1 - i][j];
            char top = painting[i][j];

            if (bottom != 0) painting[i][j] = bottom;
            else if (top != 0) painting[N - 1 - i][j] = top;
        }
    }

    return painting;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;cin>>N;

    vector<vector<char>> section(N, vector<char>(N));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>section[i][j];
        }
    }

    
}