#include "bits/stdc++.h"
using ll = long long;
using namespace std;

int main() {
    int n,m;
    vector<vector<vector<int>>> flights;
    vector<bool> visited;
    vector<ll> best;
    cin >> n >> m;
    flights.resize(n);
    visited.resize(n, false);
    best.resize(n, LONG_LONG_MAX);
    best[0] = 0;

    for(int i = m; i > 0; i--){
        int a,b,c;
        cin >> a >> b >> c;
        flights[a-1].push_back({c, b-1});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    pq.push({0,0});


    while (!pq.empty()){
        vector<ll> current;
        current = pq.top();
        pq.pop();
        if(!visited[current[1]]){
            for(vector<int>& flight : flights[current[1]]){
                if (!visited[flight[1]] && best[flight[1]] > current[0] + flight[0]) {
                    pq.push({current[0]+flight[0], flight[1]});
                    best[flight[1]] = current[0]+flight[0];
                }
            }    
        }
        visited[current[1]] = true;
    }
    /*for(int i: best){
        cout << i << " ";
    }
    cout << "\b" << "\n";
    */
    for(int i = 0; i < best.size(); i++){
        cout << best[i];
        if(i == best.size()-1) {
            cout << "\n";
        }else {
            cout << " ";
        }
    }
}