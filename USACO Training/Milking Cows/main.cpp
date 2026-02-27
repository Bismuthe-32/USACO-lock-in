/*
ID: aditya_10
LANG: C++
TASK: milk2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("milk2.in");
    ofstream cout("milk2.out");

    int N; 
    cin >> N;
    vector<pair<int,int>> intervals(N);

    int start_interval = INT_MAX;
    int end_interval = 0;

    for (int i = 0; i < N; i++) {
        cin >> intervals[i].first >> intervals[i].second;
        start_interval = min(start_interval, intervals[i].first);
        end_interval = max(end_interval, intervals[i].second);
    }

    sort(intervals.begin(), intervals.end());

    int longest_milking = 0;
    int longest_idle = 0;
    int current_milking = 0;
    int current_idle = 0;

    bool milking_started = false; // only start counting idle after first milking

    for (int time = start_interval; time < end_interval; time++) { // < end_interval to avoid counting past last milking
        bool being_milked = false;
        for (auto interval : intervals) {
            if (interval.first <= time && time < interval.second) {
                being_milked = true;
                break;
            }
        }

        if (being_milked) {
            current_milking++;
            longest_milking = max(longest_milking, current_milking);
            current_idle = 0;
            milking_started = true;
        } else if (milking_started) {
            // Only count idle after first milking has started
            current_idle++;
            longest_idle = max(longest_idle, current_idle);
            current_milking = 0;
        }
    }

    cout << longest_milking << " " << longest_idle << '\n';
}
