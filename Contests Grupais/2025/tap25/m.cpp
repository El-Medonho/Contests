#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ll = long long;

const ll md = 998244353;

template<typename T> struct FT {
    vector<T> s;
    FT(int n) : s(n) {}
    FT(const vector<T>& A) : s(A) {
        const int N = int(s.size());
        for(int a = 0; a < N; ++a) {
            if((a | (a+1)) < N) s[a | (a+1)] = (s[a | (a+1)] + s[a]) % md;
        }
    }
    void update(int pos, T dif) {
        for(; pos < int(s.size()); pos |= pos+1) s[pos] = (s[pos] + dif) % md;
    }
    T query(int pos) {
        T res = 0;
        for(; pos > 0; pos &= pos-1) res = (res + s[pos-1]) % md;
        return res;
    }
    T query(int l, int r) {
        return (query(r+1) - query(l)) % md;
    }
};

int n, m, k;
vector<vector<int>> g;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> k;
    g.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<pii> q;
    q.emplace(1, 0);
    vector<int> vis(n+1), best(n+1, INT_MAX);
    vis[1] = true;
    
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for(int v : g[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.emplace(v, d+1);
                best[v] = min(best[v], d+1);
            }
        }
    }
    if(best[2] == INT_MAX) {
        cout << 0 << '\n';
        return 0;
    }
    int days = (best[2]+(k-1))/k;
    ll max_walk = days*k;

    vector<vector<ll>> dp(n+1, vector<ll>(max_walk+1)), vis2(n+1, vector<ll>(max_walk+1));
    dp[1][0] = 1;
    vis2[1][0] = 1;
    q.emplace(1,0);
    
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for(int v : g[u]) {
            if(d+1 <= max_walk && !vis2[v][d+1]) {
                q.emplace(v, d+1);
                vis2[v][d+1] = true;
            }
            if(d+1 <= max_walk) {
                dp[v][d+1] = (dp[v][d+1] + dp[u][d]) % md;
            }
        }
    }
    
    
    vector<FT<ll>> dp2(days+1, FT<ll>(max_walk+1));
    dp2[0].update(0, 1);

    for(int j = 1; j <= days; j++) {
        for(int i = 1; i <= max_walk;i++) {
            dp2[j].update(i, (dp2[j-1].query(i) - dp2[j-1].query(max(0,i-k)) % md));
        }
    }

    ll ans = 0;
    for(int d = 1; d <= max_walk; d++) {
        ans = (ans + dp2[days].query(d, d) * dp[2][d]) % md;
    }
    cout << ans << '\n';
    return 0;
}