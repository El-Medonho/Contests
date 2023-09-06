#include "bits/stdc++.h"

using namespace std;
#define endl '\n'
#define mxn 100005
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    int rei = 0;
    int cnt = 1;
    vector<int> ind(n,1), vis(n, 0), die(n,0);
    ind[0] = 0;
    vector<vector<int>> graph(n);

    function<bool(int, int)> dfs;

    dfs = [&](int cc, int fs){

        // cout << cc << ' ' ;

        for(; ind[cc] < graph[cc].size(); ind[cc]++){
            int j = graph[cc][ind[cc]];
            if(vis[j]) {
                // ind[cc]++;
                bool jj = dfs(j, fs+1);
                if(jj) return true;
                continue;
            }
            rei = j;
            vis[j] = 1;
            ind[cc]++;
            return true;
        }

        if(fs == 0) dfs(graph[cc][0], 0);
        return false;
    };

    for(int i = 0; i < n; i++){
        int op; cin >> op;

        if(op == 1){
            int x = cnt;
            cnt++;
            int pai; cin >> pai; pai--;

            graph[pai].push_back(x);
            graph[x].push_back(pai);
        }

        else{
            int x; cin >> x; x--;
            if(x == rei){
                vis[rei] = 1;
                dfs(rei, 0);
            }else{
                vis[x] = 1;
            }
            // cout << '\n';
            cout << rei+1 << '\n';
        }
    }

    return 0;
}