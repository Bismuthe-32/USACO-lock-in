#include <iostream>

using namespace std;

int main(){
    string ab;cin>>ab;
    string said;cin>>said;

    int count=0;
    int ptr=0;
    int i=0;
    while(i<ab.length() || ptr < said.length()){
        if(i>=ab.length() && ptr < said.length()){
            i=0;
        }

        if(i==0)count++;

        if(ab[i]==said[ptr]){
            ptr++;
        }
        i++;
    }

    cout << count << '\n';
}