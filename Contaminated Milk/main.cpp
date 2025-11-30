#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main(){
    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);

    int N,M,D,S;cin>>N>>M>>D>>S;

    vector<tuple<int,int,int>> all_people(D);
    for(int i=0;i<D;i++){
        int p,m,t;cin>>p>>m>>t;
        all_people[i]={p,m,t};
    }

    vector<pair<int,int>> sick_people(S);
    for(int i=0;i<S;i++){
        int p,t;cin>>p>>t;
        sick_people[i]={p,t};
    }

    vector<int> possible_bad_milks;

    // Step 1: find all milk types that every sick person drank before getting sick
    for(int milk=1;milk<=M;milk++){
        bool possible = true;
        for(auto& [p, sick_time] : sick_people){
            bool drank_before_sick = false;
            for(auto& [person, m, t] : all_people){
                if(person==p && m==milk && t < sick_time){
                    drank_before_sick = true;
                    break;
                }
            }
            if(!drank_before_sick){
                possible = false;
                break;
            }
        }
        if(possible) possible_bad_milks.push_back(milk);
    }

    // Step 2: count all people who drank any of the possible bad milks
    set<int> infected;
    for(auto& [p,m,t] : all_people){
        for(int bad_milk : possible_bad_milks){
            if(m==bad_milk) infected.insert(p);
        }
    }

    // Step 3: print number of infected people
    cout << infected.size() << "\n";
}
