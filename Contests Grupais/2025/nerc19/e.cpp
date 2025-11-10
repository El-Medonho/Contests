#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> cnt(n, 0), dist(n, 1e9);

    queue<int> qw;
    for(int i = 0; i < m; i++){
        int x; cin >> x; x--;
        if(cnt[x] == 0) qw.push(x);
        cnt[x]++; dist[x] = 0;
    }

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();
        // cout << cc << ' ' << cnt[cc] << endl;
        if(cnt[cc] == m){
            cout << "YES\n";
            cout << cc+1 << endl;
            return 0;
        }

        for(int j: graph[cc]){
            if(!(dist[j] > dist[cc])) continue;
            if(dist[j] > 1e8) qw.push(j);
            dist[j] = dist[cc]+1;
            cnt[j] += cnt[cc];
        }
    }

    cout << "NO\n";

    return 0;
}