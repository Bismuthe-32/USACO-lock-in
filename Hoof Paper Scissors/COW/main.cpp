#include <iostream>

using ll = long long;

using namespace std;

int main(){
    ll c=0;
    ll co=0;
    ll cow=0;

    freopen("cow.in","r",stdin);
    freopen("cow.out","w",stdout); 

    int N; cin >> N;
    for(int i=0;i<N;i++){
        char ch; cin >> ch;
        if(ch=='C'){
            c++;
        }
        else if(ch=='O'){
            co+=c;
        }
        else if(ch=='W'){
            cow+=co;
        }
        
    }
    cout << cow << '\n';
}