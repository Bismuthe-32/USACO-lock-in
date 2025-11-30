#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("greetings.in","r",stdin);
    freopen("greetings.out","w",stdout);

    int B, E; cin >> B >> E;

    vector<int> bArr;
    vector<int> eArr;

    bArr.push_back(0);
    eArr.push_back(1);

    for(int i=0;i<B;i++){
        char c; int d;
        cin >> d >> c;
        if(c=='L'){
            for(int j = bArr[bArr.size()-1]-1; j >= bArr[bArr.size()-1]-d; j--){
                bArr.push_back(j);
            }
        }
        else if(c=='R'){
            for(int j = bArr[bArr.size()-1]+1; j <= bArr[bArr.size()-1]+d; j++){
                bArr.push_back(j);
            }
        }
    }
    for(int i=0;i<E;i++){
        char c; int d;
        cin >> d >> c;
        if(c=='L'){
            for(int j = eArr[eArr.size()-1]-1; j >= eArr[eArr.size()-1]-d; j--){
                eArr.push_back(j);
            }
        }
        else if(c=='R'){
            for(int j = eArr[eArr.size()-1]+1; j <= eArr[eArr.size()-1]+d; j++){
                eArr.push_back(j);
            }
        }
    }

    int min_len = min(bArr.size(), eArr.size());

    int c=0;

    for(int i=0; i < min_len; i++){
        if(bArr[i]==eArr[i]){
            c++;
        }
    }

    cout << c;
}