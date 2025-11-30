#include <iostream>

using namespace std;

int main(){
    int x1A,x1B,x1C,y1A,y1B,y1C,x2A,x2B,x2C,y2A,y2B,y2C;

    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);

    cin >> x1A >> y1A >> x2A >> y2A 
        >> x1B >> y1B >> x2B >> y2B
        >> x1C >> y1C >> x2C >> y2C;

    int xIntOne = max(
        min(x2C,x2A) - max(x1C, x1A),
        0
    );

    int xIntTwo = max(
        min(x2C,x2B) - max(x1C, x1B),
        0
    );

    int yIntOne = max(
        min(y2C,y2A) - max(y1C, y1A),
        0
    );

    int yIntTwo = max(
        min(y2C,y2B) - max(y1C,y1B),
        0
    );

    int totalArea = abs(x1A-x2A)*abs(y1A-y2A)+abs(x1B-x2B)*abs(y1B-y2B);

    totalArea -= xIntOne*yIntOne + xIntTwo*yIntTwo;

    cout << totalArea << '\n';

}