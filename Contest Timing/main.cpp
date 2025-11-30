#include <iostream>

using namespace std;

int main(){
    freopen("ctiming.in","r",stdin);
    freopen("ctiming.out","w",stdout);

    int D,H,M;cin>>D>>H>>M;

    int startD=11,startH=11,startM=11;

    int diffD=D-startD,diffH=H-startH,diffM=M-startM;

    cout << diffD*1440+diffH*60+diffM;
}