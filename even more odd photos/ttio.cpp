#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;cin>>N;
    int e_count = 0;
    int o_count = 0;
    for(int i=0;i<N;i++){
        int n;cin>>n;
        if(n%2==0)e_count++;
        else o_count++;
    }

    int count=0;
    int sum_even = -1;
    int remainder=0;
    bool swich = false;

    while(e_count > 0 || o_count > 0){
        if(swich){
            remainder=remainder^1;
        }
        if(remainder==0){
            // sum_even must be true
            // if sum_even is 0 (odd), then add an odd number
            // if sum_even is 1 (even), then break
            // if sum_even is -1 (undet), then add an even number
            if(sum_even==-1){
                if(e_count>0){
                    e_count--;sum_even=1;
                }
                else{
                    // grab z
                }
            } 
        }
        else{
            //add one from odd_array
        }
    }
}