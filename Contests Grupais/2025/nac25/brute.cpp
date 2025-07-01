#include "bits/stdc++.h"

using namespace std;

// #define endl '\n'
typedef long long ll;
const int mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


ll expo(ll b, ll e){
    ll resp = 1;
    while(e){
        if (e & 1){
            resp = (resp * b)%mod;
        }
        b = (b * b)%mod;
        e>>=1;
    }
    return resp;
}

int brute(int n, vector<pair<int, int> > edges){
    vector<vector<int>> graph(n);
    for(auto [a, b]:edges){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i < n; i++){
        if(graph[i].size() == 1) {
            edges.emplace_back(0, i);
        }
    }

    int m = edges.size();

    ll ans = 0;
    vector<int> pai(n, 0);

    auto ff = [&](auto&&self, int x) -> int {
        if(pai[x] == x) return x;
        return pai[x] = self(self, pai[x]);
    };

    auto uu = [&](auto&&self, int x, int y) -> bool {
        x = ff(ff, x); y = ff(ff, y);
        if(x == y) return false;

        pai[x] = y;
        return true;
    };

    for(int mask = 0; mask < (1<<m); mask++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(mask & (1<<j)) cnt++;
        }

        if(cnt != n-1) continue;
        
        for(int i = 0; i < n; i++){
            pai[i] = i;
        }
        
        bool kk = true;

        for(int j = 0; j < m; j++){
            if(!(mask & (1<<j))) continue;
            auto[x, y] = edges[j];
            if(!uu(uu,x,y)) {
                kk = false;
                break;
            }
        }

        if(kk) ans++;
    }
    return ans;
}

vector<pair<int, int>> pruferCodeToTree(vector<int> &pruferCode){
    unordered_map<int, int> nodeCount;
    set<int> leaves;
    int len = (int)pruferCode.size();
    int node = len+2;

    for(int i=0; i<len; i++){
        int t = pruferCode[i];
        nodeCount[t]++;
    }
    for(int i=1; i<=node; i++){
        if(nodeCount.find(i) == nodeCount.end()) leaves.insert(i);
    }
    vector<pair<int, int>> edges;

    for(int i=0; i<len; i++){
        int a = pruferCode[i];
        int b = *leaves.begin();

        edges.push_back({a, b});
        leaves.erase(b);
        nodeCount[a]--;
        if(nodeCount[a] == 0) leaves.insert(a);
    }
    edges.push_back({*leaves.begin(), *leaves.rbegin()});
    return edges;
}

vector<pair<int, int> > genRandomTree(int n){
    vector<int> pruferCode;
    for(int i=0; i<n-2; i++){
        pruferCode.push_back(rng()%(n-1)+1);
    }
    auto edges = pruferCodeToTree(pruferCode);
    for(auto &p:edges){
        p.first--, p.second--;
    }
    return edges;
}

int meu(int n, vector<pair<int, int>> edges){
    vector<vector<int>> graph(n);
    for(auto [a, b]:edges){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i < n; i++){
        if(graph[i].size() == 1) {
            edges.emplace_back(0, i);
        }
    }

    vector<ll> dp(n, 1), dp2(n, 1);
    
    auto dfs = [&](auto&&self, int cc, int pai) -> void {
        ll sum = 1;
        for(int j: graph[cc]){
            if(j == pai) continue;
            if(graph[j].size() != 1){
                self(self, j, cc);
            }

            dp[j] += dp2[j];
            dp[j] %= mod;

            sum = sum*dp[j]%mod;
        }
        dp[cc] = sum; dp2[cc] = 0;

        for(int j: graph[cc]){
            if(j == pai) continue;
            ll cs = sum * expo(dp[j], mod-2);
            cs = cs*dp2[j]%mod;
            dp2[cc] += cs; dp2[cc] %= mod;
        }
    };

    dfs(dfs, 0, -1);

    return dp[0];
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    bool ok = true;

    while(ok){
        int n = 21;

        auto edges = genRandomTree(n);

        int ans = brute(n, edges);

        int meuu = meu(n, edges);
        
        if(meuu != ans){
            cout << meuu << ' ' << ans << endl;
            for(auto[x, y]: edges){
                cout << x << ' ' << y << '\n';
            }
            ok = false;
        }

        else cout << "ok" << endl;
    }

    return 0;
}