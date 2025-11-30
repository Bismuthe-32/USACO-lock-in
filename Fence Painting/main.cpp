#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    pair<int,int> farmer;
    cin >> farmer.first >> farmer.second;

    pair<int,int> bessie;
    cin >> bessie.first >> bessie.second;

    if (farmer.second < bessie.first || bessie.second < farmer.first) {
        // no overlap
        cout << (farmer.second - farmer.first) + (bessie.second - bessie.first) << '\n';
    } else {
        // overlap
        cout << max(farmer.second, bessie.second) - min(farmer.first, bessie.first) << '\n';
    }
}