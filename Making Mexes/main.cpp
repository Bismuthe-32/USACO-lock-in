#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int N;cin>>N;

    map<int,int> slots;

    for(int i=0;i<=N;i++){
        slots[i]=0;
    }

    for(int i=0;i<N;i++){
        int a;cin>>a;
        slots[a]++;
    }

    vector<int> empties(N+1,0); // empties[k] shows amount of empty slots before k

    for(int i=1;i<=N;i++){
        empties[i] = empties[i-1]+(int)(slots[i-1]==0);
    }

    for(int k=0;k<=N;k++){
        int count = slots[k];
        int in_the_air = slots[k];
        int empty_slots=empties[k];
        if(empty_slots>in_the_air){
            count+=empty_slots-in_the_air;
        }
        cout << count << '\n';
    }
}