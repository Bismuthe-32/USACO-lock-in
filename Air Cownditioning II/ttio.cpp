#include <iostream>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

struct AirCon {
    int a,b,p,m;
};

struct Cow {
    int s,t,c;
};

bool comp(AirCon& a, AirCon& b){
    return a.m<b.m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;cin>>N>>M;
    int current[100];
    int required[100];
    for(int i=0;i<100;i++) current[i]=0;
    for(int i=0;i<N;i++) required[i]=0;

    vector<Cow> cows(N); // [s,t], and c
    vector<AirCon> air_cons(M);

    for(int i=0;i<N;i++){
        cin>>
        cows[i].s>>
        cows[i].t>>
        cows[i].c;

        cows[i].s--;
        cows[i].t--;

        for(int shed=cows[i].s;shed<=cows[i].t;shed++){
            required[shed] = cows[i].c;
        }
    }
    for(int i=0;i<M;i++){
        cin>>
        air_cons[i].a>>
        air_cons[i].b>>
        air_cons[i].p>>
        air_cons[i].m;

        air_cons[i].a--;
        air_cons[i].b--;
    }

    int cost = 0;

    for(int cow = 0 ; cow<N;cow++){
        int i=0;
        int max_is = 0;
        int max_i = 0;
        while(i < M){
            int s = cows[cow].s;
            int t = cows[cow].t;
            int c = cows[cow].c;

            int a = air_cons[i].a;
            int b = air_cons[i].b;

            int p = air_cons[i].p;
            int m = air_cons[i].m;

            int is_x1 = max(s,a);
            int is_x2 = min(t,b);

            if(abs(is_x2-is_x1>0)>max_is){
                max_is=abs(is_x2-is_x1>0);
                max_i=i;
            }

            i++;

        }

        air_cons[max_i].a

    }
}