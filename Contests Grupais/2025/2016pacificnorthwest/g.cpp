#include "bits/stdc++.h"

using namespace std;

struct bm_t{
    int N,M,T;
    vector<vector<int>> adj;
    vector<int> match,seen;
    bm_t(int a,int b) : N(a), M(a+b), T(0),adj(M), match(M,-1), seen(M,-1){}
    void add_edge (int a,int b){ adj[a].push_back(b+N);}
    bool dfs(int cur){
        if(seen[cur] == T) return false;
        seen[cur] = T;
        for(int nxt : adj[cur]) if(match[nxt] == -1){
            match[nxt] = cur, match[cur] = nxt;
            return true;
        }
        for(int nxt: adj[cur]) if(dfs(match[nxt])){
            match[nxt] = cur, match[cur] = nxt;
            return true;
        }
        return false;
    }
    int solve(){
        int res = 0;
        for(int cur = 1; cur;){
            cur = 0; ++T;
            for(int i = 0 ; i < N; ++i) if(match[i] == -1){
                cur += dfs(i);
            }
            res += cur;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    int ans = 0;

    vector<int> pai(n*m);

    for(int i = 0; i < n*m; i++) pai[i] = i;

    auto ff = [&](auto&& self, int x) -> int{
        if(x == pai[x]) return x;
        return pai[x] = self(self,pai[x]);
    };

    auto uu = [&](auto&& self, int x, int y) -> void{
        x = ff(ff,x), y = ff(ff,y);

        if(x == y) return;

        pai[x] = y;
    };

    vector<string> arr(n);

    for(string &s: arr) cin >> s;

    vector<vector<int>> pol(n, vector<int>(m, 0));
    vector<vector<int>> val(n, vector<int>(m, -1));

    vector<pair<int,int>> nxt = {{0,1},{1,0},{0,-1},{-1,0}};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != 'L') {pai[i*m+j] = -1; continue;}
            for(auto[X,Y]: nxt){
                int xn = i+X, yn = j+Y;
                if(xn < 0 || xn >= n || yn < 0 || yn >= m) continue;
    
                if(arr[xn][yn] == 'L') uu(uu,i*m+j, xn*m+yn);

                pol[xn][yn] = 1;
            }
            pol[i][j] = 1;
        }
    }

    int cnt = 0, a = 0, b = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != 'C' || pol[i][j]) continue;

            cnt++;

            if((i+j)%2) val[i][j] = b++;
            else val[i][j] = a++;
        }
    }

    bm_t bm(a,b);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != 'C' || pol[i][j]) continue;

            for(auto[X,Y]: nxt){
                int xn = i+X, yn = j+Y;
                if(xn < 0 || xn >= n || yn < 0 || yn >= m || val[xn][yn] == -1) continue;

                if((i+j)%2){
                    continue;
                }
                else bm.add_edge(val[i][j], val[xn][yn]);
            }
        }
    }

    for(int i = 0; i < n*m; i++){
        if(pai[i] != -1 && ff(ff,i) == i) ans++;
    }

    int h = bm.solve();

    cout << cnt-h+ans << '\n';


    return 0;
}