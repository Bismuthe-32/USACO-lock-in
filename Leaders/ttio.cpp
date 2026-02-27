#include <iostream>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;cin>>N;
    string cows;cin>>cows;
    vector<int> Es(N);
    int min_g_pos = 0;
    int max_g_pos = 0;
    int min_h_pos = 0;
    int max_h_pos = 0;
    bool stop_g = false;
    bool stop_h = false;
    for(int i=0;i<N;i++){
        cin>>Es[i];
        Es[i]--;
        if(!stop_g && cows[i]=='G'){
            min_g_pos=i;
            stop_g=true;
        }
        if(!stop_h && cows[i]=='H'){
            min_h_pos=i;
            stop_h=true;
        }
        if(cows[i]=='G'){
            max_g_pos = max(max_g_pos, i);
        }
        if(cows[i]=='H'){
            max_h_pos = max(max_h_pos, i);
        }
    }

    unordered_map<int,pair<bool,bool>> mp;
    for (int i = 0; i < N; i++) {
        mp[i] = {false, false};
    }

    // check if contains both
    if(Es[min_g_pos] >= max_g_pos){
        mp[min_g_pos].first = true;
    }if(Es[min_h_pos] >= max_h_pos){
        mp[min_h_pos].first = true;
    }

    for(auto& [k,v] : mp){
        //cout << "COW ID: " << k << " DOES COW COVER ALL? " << (v.first ? "true" : "false") << '\n';
    }

    // for all cows that are G, do they have the leader of H?
    // this is only true if a cow in H has all the cows in the first place.
    // therefore:
    set<pair<int,int>> possible_leaders;
    vector<int> leader_of_h_poses;
    vector<int> leader_of_g_poses;


    for(int i=0;i<N;i++){
        if(mp[i].first && cows[i]=='H'){ /* contains all cows*/
            //cout << "Leader @ " << i << '\n';
            leader_of_h_poses.push_back(i);
            break;
        }
    }
    
    for(int i=0;i<N;i++){
        if(mp[i].first && cows[i]=='G'){ /* contains all cows*/
            //cout << "Leader @ " << i << '\n';
            leader_of_g_poses.push_back(i);
            break;
        }
    }


    // check if any of g contains h leaders, or if any of h contains g leaders

    for(int i=0;i<N;i++){
        if(cows[i]=='H'){
            for(int j=0;j<leader_of_g_poses.size();j++){
                
                if(i < leader_of_g_poses[j] && leader_of_g_poses[j] <= Es[i]){
                    //cout << i << "->" << Es[i] << " ; " << leader_of_g_poses[j] << "(H)\n";
                    possible_leaders.insert({i,leader_of_g_poses[j]});
                }
            }
        }

        if(cows[i]=='G'){
            for(int j=0;j<leader_of_h_poses.size();j++){
                
                if(i < leader_of_h_poses[j] && leader_of_h_poses[j] <= Es[i]){
                    //cout << i << "->" << Es[i] << " ; " << leader_of_h_poses[j] << "(G) \n";
                    possible_leaders.insert({i,leader_of_h_poses[j]});
                }
            }
        }
    }

    for(auto [g,h] : possible_leaders){
        //cout << g << " " << h << '\n';
    }

    /* We hv only calculated if H contains leader of G, where G has all of her species, and G contains H which contains all of her species*/
    if(leader_of_g_poses.size() > 0 && leader_of_h_poses.size() > 0){
    possible_leaders.insert({leader_of_g_poses[0],leader_of_h_poses[0]});
    }

    cout << possible_leaders.size() << '\n';
}