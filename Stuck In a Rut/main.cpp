#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct IntersectionPoint {
  int cow1, cow2, time1, time2;

  bool operator < (const IntersectionPoint &other) const {
    if(time2 == other.time2){
      if(cow1 == other.cow1){
        if(cow2 == other.cow2){
          return time1 < other.time1;
        }
        return cow2 < other.cow2;
      }
      return cow1 < other.cow1;
    }
    return time2 < other.time2;
  }
};

int main(){
  int N;cin>>N;
  vector<char> dir(N);
  vector<int> x(N);
  vector<int> y(N);
  for(int i=0;i<N;i++)
    cin >> dir[i] >> x[i] >> y[i];
  vector<IntersectionPoint> intersect;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(dir[i]!=dir[j]){
        //Constantize i j representing east and north
        int a=i, b=j;
        if(dir[a] == 'N'){
          swap(a,b);
        }
        if(x[a] < x[b] && y[a] > y[b]){
          int timeA = x[b]-x[a];
          int timeB = y[a] - y[b];
          if(timeA > timeB){
            intersect.push_back({b, a, timeB, timeA}); // B reaches first
          }
          else if(timeB > timeA){
            intersect.push_back({a,b,timeA,timeB});
          }
        }
      }
    }
  }
  sort(intersect.begin(), intersect.end());

  vector<int> stopped(N, 1e9);
  for(IntersectionPoint& ip : intersect){
    if(ip.time1 < stopped[ip.cow1] && ip.time2 < stopped[ip.cow2]){
      stopped[ip.cow2] = ip.time2;
    }
  }

  for(int i=0;i<N;i++){
    if(stopped[i]==1e9) cout << "Infinity\n";
    else cout << stopped[i] << '\n';
  }
}