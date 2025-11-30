#include <bits/stdc++.h>
using namespace std;

struct Interaction {
    int time;
    int a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    string finalState;
    cin >> finalState;

    vector<Interaction> events(T);
    for(int i = 0; i < T; i++){
        cin >> events[i].a >> events[i].b >> events[i].time;
        events[i].a--; events[i].b--; // convert to 0-index
    }

    // Sort interactions by time
    sort(events.begin(), events.end(), [](Interaction x, Interaction y){
        return x.time < y.time;
    });

    int possiblePatientZero = 0;
    int minInfected = N, maxInfected = 0;
    int minK = INT_MAX, maxK = 0;

    for(int patient = 0; patient < N; patient++){
        for(int K = 0; K <= T; K++){ // K can be at most T
            vector<int> infected(N, 0);
            vector<int> remaining(N, K); // number of times cow can infect

            infected[patient] = 1; // patient zero

            for(auto &e : events){
                int a = e.a, b = e.b;
                // a infects b
                if(infected[a] && remaining[a] > 0 && !infected[b]){
                    infected[b] = 1;
                    remaining[a]--;
                }
                // b infects a
                if(infected[b] && remaining[b] > 0 && !infected[a]){
                    infected[a] = 1;
                    remaining[b]--;
                }
            }

            // check if final state matches
            bool match = true;
            for(int i=0;i<N;i++){
                if((infected[i]? '1':'0') != finalState[i]){
                    match = false;
                    break;
                }
            }

            if(match){
                possiblePatientZero++;
                int countInfected = accumulate(infected.begin(), infected.end(), 0);
                minInfected = min(minInfected, countInfected);
                maxInfected = max(maxInfected, countInfected);
                minK = min(minK, K);
                maxK = max(maxK, K);
                goto nextPatient; // K found, no need to try higher Ks
            }
        }
        nextPatient:;
    }

    cout << possiblePatientZero << " " << minInfected << " " << maxInfected << " " << minK << " " << maxK << "\n";

    return 0;
}
