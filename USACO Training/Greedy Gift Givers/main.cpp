/*
ID: aditya_10
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);

    int N; 
    cin >> N;

    vector<string> order(N);
    unordered_map<string, int> values;

    // Read names in order
    for(int i = 0; i < N; i++) {
        cin >> order[i];
        values[order[i]] = 0;
    }

    // Process gift giving
    for(int i = 0; i < N; i++) {
        string name; 
        cin >> name;

        int value, num_people;
        cin >> value >> num_people;

        if (num_people > 0) {
            int divided = value / num_people;
            int total_given = divided * num_people;

            values[name] -= total_given;

            for(int j = 0; j < num_people; j++) {
                string receiver;
                cin >> receiver;
                values[receiver] += divided;
            }
        }
        else {
            // If giving to 0 people, nothing happens
        }
    }

    // Output in original order
    for (string &name : order) {
        cout << name << " " << values[name] << "\n";
    }

    return 0;
}
