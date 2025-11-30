#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<long long> nums(7);

    for(int i=0;i<7;i++){
        cin >> nums[i];
    }

    sort(nums.begin(),nums.end());

    long long A = nums[0];
    long long B = nums[1];
    long long ABC = nums[6];

    long long C = ABC - A - B;

    cout << A << " " << B << " " << C << "\n";
}