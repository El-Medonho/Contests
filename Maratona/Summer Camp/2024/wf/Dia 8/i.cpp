#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n; n = 2*n;

    int m; cin >> m;

    vector<vector<int>> graph(n);


    vector<int> pai(n), peso(n, 1);

    for(int i = 0; i < n; i++){
        pai[i] = i;
    }

    function<int(int)> ff;

    ff = [&](int x){
        if(pai[x] == x) return x;
        return pai[x] = ff(pai[x]);
    };

    function<void(int,int)> uu;

    uu = [&](int x, int y){
        x = ff(x);
        y = ff(y);

        if(x == y) return;

        if(peso[x] > peso[y]) swap(x,y);

        pai[x] = y;
        peso[y] += peso[x];

        return;
    };

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        // a--; b--;

        int x = ff(a), y = ff(b);

        if(x == y) continue;

        uu(x,y);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> vis(n, 0), did(n, 0);

    function<void(int,int)> dfs;

    vector<array<int,3>> ans(0);

    vector<vector<int>> match(n);

    dfs = [&](int cc, int last){

        vis[cc] = 1;

        for(int j: graph[cc]){
            if(j == last) continue;

            dfs(j, cc);
        }

        bool ok = true;

        int h = -1;

        for(int j: match[cc]){
            if(h != -1){
                ans.push_back({h,j,cc});
                did[h] = 1; did[j] = 1;
                h = -1;
            }
            else h = j;
        }

        if(h != -1){
            ok = false;
            ans.push_back({cc, h, -1});
            did[h] = 1;
            did[cc] = 1;
        }

        if(ok){
            match[last].push_back(cc);
        }

        return;
    };

    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i,i);
    }

    for(int i = 0; i < n; i++){
        if(!did[i]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "POSSIBLE\n";

    for(auto[x, y, k]: ans){
        // cout << x + 1 << ' ' << y+1 << ' ' << k+1 << '\n';
        cout << x << ' ' << y << ' ' << k << '\n';
    }


    return 0;
}