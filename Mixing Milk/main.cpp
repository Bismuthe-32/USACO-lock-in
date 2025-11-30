#include <iostream>
#include <vector>

using namespace std;

int capacities[3];
int amt_milk[3];

int main(){
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);

    for(int i=0;i<3;i++){
        cin >> capacities[i] >> amt_milk[i];
    }

    for(int i=0;i<100;i++){
        int starting_cup = i % 3;
        int end_cup = (starting_cup+1) % 3;

        if(amt_milk[starting_cup]+amt_milk[end_cup] <= capacities[end_cup]){
            amt_milk[end_cup]+=amt_milk[starting_cup];
            amt_milk[starting_cup]=0;
        }
        else {
            int pour_amt = capacities[end_cup]-amt_milk[end_cup];
            amt_milk[end_cup]+=pour_amt;
            amt_milk[starting_cup]-=pour_amt;
        }
    }

    for(auto& amt : amt_milk){
        cout << amt << '\n';
    }
}