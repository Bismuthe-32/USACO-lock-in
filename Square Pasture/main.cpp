#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);

    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    int xUnion;
    int yUnion;

    int xSpace = max(x2,x4)-min(x1,x3);

    int ySpace = max(y2,y4)-min(y1,y3);

    cout << max(xSpace,ySpace)*max(xSpace,ySpace) << '\n';


}