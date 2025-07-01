// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mod = 1e9+7;

ll expo(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%mod;
        b = b*b%mod;
        e>>=1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll ans = 0;

    int n,m,k; cin >> n >> m >> k;

    vector<ll> fat(n+1, 1);

    for(int i = 1; i <= n; i++) fat[i] = (fat[i-1]*i) % mod;

    vector<vector<pair<int,int>>> graph(n);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        int c; cin >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int last = 0, tot = -1, qtt_last = -1;
    // n-tot escolhe k

    vector<int> dist(n, 1e9);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0}); dist[0] = 0;

    ll prob = 0;

    n--;

    ll h = fat[n] * expo(fat[k] * fat[n-k] % mod, mod-2) % mod;
    h = expo(h, mod-2);

    while(!pq.empty()){
        auto [d, cc] = pq.top(); pq.pop();
        if(d != dist[cc]) continue;

        if(d != last && last != 0){
            if(n-tot < k) break;
            ll p1 = fat[n-tot];
            p1 = p1 * expo(fat[k] * fat[n-tot-k] % mod, mod-2) % mod;

            ll p2 = fat[n-(tot-qtt_last)];
            p2 = p2 * expo(fat[k] * fat[n-(tot-qtt_last)-k] % mod, mod-2) % mod;

            ll p = p2 - p1 + mod; p %= mod;
            p *= h; p %= mod;

            prob += p; prob %= mod;

            ans += p * last % mod; ans %= mod;

            qtt_last = 0;
        }

        last = d;
        tot++;
        qtt_last++;

        for(auto [j, c]: graph[cc]){
            if(dist[j] <= c + d) continue;
            dist[j] = c+d;
            pq.push({c+d, j});
        }
    }

    ans = (ans + ((1-prob+mod)%mod * last % mod)) % mod;

    cout << ans << endl;


    return 0;
}