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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define endl "\n"
#define f first
#define s second
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

signed solve(){

    int n; cin >> n;

    int m = 0;
    vector<int> mul(0), corr(n, -1);

    vector<vector<int>> graph(n);

    vector<pair<ll,ll>> val(n, {0,0});
    vector<int> tipo(n, 1);

    for(int i = 1; i < n; i++){
        int p,t,s,g; cin >> p >> t >> s >> g; p--;
        graph[p].push_back(i);
        tipo[i] = t;
        val[i] = {s,g};
        if(t == 2) {mul.push_back(i); corr[i] = mul.size()-1;}
    }

    m = mul.size();

    ll str = 1;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq, pq2;

    pq.push({0,0});

    while(!pq.empty()){
        int cc = pq.top().second; pq.pop();
        if(val[cc].f > str) continue;

        str += val[cc].s;
        str = min(ll(1e9+50), str);

        for(int j: graph[cc]){
            if(tipo[j] == 2) continue;
            pq.push({val[j].f, j});
        }
    }

    vector<ll> dp(1<<m, -1);

    dp[0] = str;

    for(int g = 0; g < 1<<m; g++){
        str = dp[g];
        if(str == -1) continue;

        int cnt = 0;

        pq.push({0,0});

        vector<int> reach(n, 0);

        while(!pq.empty()){
            int cc = pq.top().second; 
            if(str < val[cc].first) break;
            pq.pop();

            cnt++;

            for(int j: graph[cc]){
                reach[j] = 1;
                if((tipo[j] == 2 && !(g & (1 << corr[j])))) continue;
                pq.push({val[j].f, j});
            }
        }

        if(cnt == n){
            cout << "Yes\n";
            return 0;
        }

        ll pad = str;

        for(int k = 0; k < m; k++){
            str = pad;
            int ver = mul[k];
            if( (g & (1<<k)) || !reach[ver] ) continue;
            str = min(ll(1e9+50), str * val[ver].second);

            pq2 = pq;

            pq2.push( {0, ver} );

            while(!pq2.empty()){
                int cc = pq2.top().second; pq2.pop();
                if(val[cc].f > str) continue;

                str += tipo[cc] == 2 ? 0 : val[cc].s;
                str = min(ll(1e9+50), str);

                for(int j: graph[cc]){
                    if(tipo[j] == 2) continue;
                    pq2.push({val[j].f, j});
                }
            }

            dp[g ^ (1<<k)] = max(dp[g ^ (1<<k)], str);
        }

        while(!pq.empty()) pq.pop();
    }

    cout << "No\n";

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}