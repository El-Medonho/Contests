#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;//dist aresta, index pra onde vai

int t;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin >> t;

    while(t--) {
        cin >> s;

        vector<int> dist(s.size()+1, INT_MAX), last(s.size()+1, -1), jumps(s.size()+1, INT_MAX);
        vector<vector<pii>> adj(s.size()+1, vector<pii>());
        vector<bool> vis(s.size()+1, false);

        for(int i = 1; i < adj.size(); i++) {
            for(int j = 1; j < adj.size(); j++) {
                if(i != j) adj[i].emplace_back(abs((s[i-1] - 'a') - (s[j-1] - 'a')) ,j);
            }
        }

        auto compare = [&] (int a, int b) {
            if(dist[a] > dist[b]) return true;
            else if(dist[b] > dist[a]) return false;
            else if(jumps[a] > jumps[b]) return false;
            else return true;
        };

        priority_queue<int, vector<int>, decltype(compare)> prioq(compare);

        dist[1] = 0;
        jumps[1] = 0;
        prioq.push(1);

        while(!prioq.empty()) {
            int ind = prioq.top();
            prioq.pop();
            
            if(vis[ind]) continue;
            vis[ind] = true;

            for(pii& edge : adj[ind]) {
                int cost = edge.first, dest = edge.second;

                if(!vis[dest] && dist[dest] >= cost+dist[ind] ) {
                    if(dist[dest] == cost+dist[ind]) {
                        if(jumps[dest] < jumps[ind]+1) {
                            prioq.push(dest);

                            dist[dest] = cost+dist[ind];
                            last[dest] = ind;
                            jumps[dest] = jumps[ind]+1;
                        }
                    }else {
                        prioq.push(dest);

                        dist[dest] = cost+dist[ind];
                        last[dest] = ind;
                        jumps[dest] = jumps[ind]+1;
                    }
                }
            }

        }

        cout << dist[s.size()] << " " << jumps[s.size()]+1 << "\n";

        int curr = s.size();
        stack<int> path;
        while(last[curr] != -1) {
            path.push(curr);
            curr = last[curr];
        }
        path.push(curr);

        while(!path.empty()) {
            cout << path.top();
            path.pop();
            if(!path.empty()) cout << " ";
        }
        cout << "\n";
    }
}