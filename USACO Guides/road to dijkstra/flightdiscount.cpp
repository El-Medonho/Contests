#include "bits/stdc++.h"
using ll = long long;
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    /* plan is to have two dijkstras */
    vector<vector<pair<int, int>>> flights;
    vector<pair<ll, ll>> best;
    vector<pair<bool, bool>> visited;
    flights.resize(n);
    best.resize(n, {LONG_LONG_MAX, LONG_LONG_MAX});
    visited.resize(n, {false, false});

    for(int i = 0; i< m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        flights[a-1].push_back({c, b-1});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pqhalf;
    pq.push({0,0});
    best[0].first = 0; best[0].second = 0;

    while(!pq.empty()){                 //first dijkstra
        pair<ll, int> current = pq.top();
        pq.pop();
        if(!visited[current.second].first){
            for (pair<int, int>& flight : flights[current.second]){
                if(!visited[flight.second].first and best[flight.second].first > current.first + flight.first){
                    pq.push({current.first + flight.first, flight.second});
                    best[flight.second].first = current.first + flight.first;
                }
                if (best[flight.second].second > current.first + (flight.first/2)){
                    pqhalf.push({current.first + (flight.first/2), flight.second});
                    best[flight.second].second = current.first + (flight.first/2);
                }
            }
        }
        visited[current.second].first = true;
    }

    cout << "penis\n";

    while(pqhalf.top().second != n-1){      //second dijkstra
        pair<ll, int> current = pqhalf.top();
        pqhalf.pop();
        if(!visited[current.second].second){
            for (pair<int, int>& flight : flights[current.second]){
                if(!visited[flight.second].second and best[flight.second].second > current.first + flight.first){
                    pqhalf.push({current.first + flight.first, flight.second});
                    best[flight.second].second = current.first + flight.first;
                }
            }
        }
        visited[current.second].second = true;
    }

    cout << best[n-1].second << "\n";
}