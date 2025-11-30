#include <iostream>
#include <vector>

using namespace std;

int segmentLimit[100];
int segmentBessie[100];

int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);

    int N;
    int M;
    cin >>N>>M;

    vector<pair<int,int>> limitSpeeds(N);
    vector<pair<int,int>> bessieSpeeds(M);

    for(int i=0;i<N;i++){
        cin >> limitSpeeds[i].first >> limitSpeeds[i].second;
    }
    for(int i=0;i<M;i++){
        cin >> bessieSpeeds[i].first >> bessieSpeeds[i].second;
    }



    int pos=-1;

    for(auto& p : limitSpeeds){
        int length = p.first;
        int speed = p.second;

        for(int i=pos+1;i<=pos+length;i++){
            segmentLimit[i]=speed;
        }
        pos+=length;
    }



    pos=-1;

    for(auto& p : bessieSpeeds){
        int length = p.first;
        int speed = p.second;

        for(int i=pos+1;i<=pos+length;i++){
            segmentBessie[i]=speed;
        }
        pos+=length;
    }

    int maxSpeed=0;
    for(int i=0;i<100;i++){
        maxSpeed=max(maxSpeed,segmentBessie[i]-segmentLimit[i]);
    }

    cout << maxSpeed << '\n';
}