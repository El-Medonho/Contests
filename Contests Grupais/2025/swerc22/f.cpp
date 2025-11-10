#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed solve(){

    int n,m; cin >> n >> m;

    vector<vector<int>> graph(n), matrix(n, vector<int>(n, -1));


    vector<int> own(m, 0);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(i); graph[b].push_back(i);
        matrix[a][b] = i; matrix[b][a] = i;
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        if(graph[i].size() < n-1 && ok){
            ok = false;
            for(int j: graph[i]) own[j] = 1;
        } 
    }

    if(ok){
        if(n == 3){
            cout << 3 << endl;
            cout << 1 << ' ' << 2 << ' ' << 3 << endl;
            return 0;
        }
        cout << 3 << endl;
        for(int i = 1; i < n-1; i++) own[matrix[0][i]] = 1;
        for(int i = 1; i < n-1; i++) own[matrix[n-1][i]] = 2;
        // own[matrix[0][n-1]] = 3;



        for(int i = 0; i < m; i++){
            cout << own[i]+1 << ' ';
        }
        cout << endl;
    }

    else{
        cout << 2 << endl;
        for(int i = 0; i < m; i++) cout << own[i]+1 << ' ';
        cout << endl;
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}