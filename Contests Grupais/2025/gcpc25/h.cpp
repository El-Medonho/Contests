#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<vector<int>> graph(n);

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
    } 

    int a,b; cin >> a >> b; a--; b--;

    queue<int> qw;
    vector<int> vis1(n, 0), vis2(n, 0);
    vis1[a] = 1; qw.push(a);

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();
        for(int j: graph[cc]){
            if(vis1[j]) continue;
            vis1[j] = 1;
            qw.push(j);
        }
    }

    vis2[b] = 1; qw.push(b);

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();
        for(int j: graph[cc]){
            if(vis2[j]) continue;
            vis2[j] = 1;
            qw.push(j);
        }
    }

    for(int i = 0; i < n; i++){
        if(vis1[i] && vis2[i]){
            cout << "yes\n";
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << "no\n";

    return 0;
}