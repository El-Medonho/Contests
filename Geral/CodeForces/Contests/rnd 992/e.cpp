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

#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;

signed solve(){
    
    int n; cin >> n; int q; cin >> q;

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<pair<int,int>>> query(n);

    for(int i = 0; i < q; i++){
        int v,p; cin >> v >> p; v--;
        query[v].push_back({p,i});
    }

    for(int i = 0; i < n; i++){
        sort(query[i].begin(), query[i].end());
    }

    vector<ll> ans(q);

    int lim = sqrt(n)+2;

    vector<ll> oqtt(lim, 0), eqtt(lim, 0);
    multiset<ll> obig, ebig;

    ll osum = 0, esum = 0;

    function<void(int,int,int)> dfs;

    dfs = [&](int cc, int last, int d){
        if(d){
            if(d%2){
                if(graph[cc].size() >= lim) obig.insert(-((int)graph[cc].size()));
                else oqtt[graph[cc].size()]++;

                osum++;
                esum += (2*(int)graph[cc].size())-1;

                int cnt = 0, pegos = 0;

                ll cans = osum;

                while(cnt < query[cc].size() && query[cc][cnt].first == 0){
                    ans[query[cc][cnt].second] = cans;
                    cnt++;
                }

                for(ll j: ebig){
                    j = -j;
                    cans -= (2*j)-1; cans++;
                    while(cnt < query[cc].size() && pegos + 1 == query[cc][cnt].first){
                        ans[query[cc][cnt].second] = cans;
                        cnt++;
                    }
                    pegos++;
                }

                for(int j = lim-1; j > -1; j--){
                    while(cnt < query[cc].size() && pegos + eqtt[j] >= query[cc][cnt].first){
                        int aPegar = query[cc][cnt].first - (pegos);
                        ll ccans = cans - aPegar*(2*j-1) + aPegar;
                        ans[query[cc][cnt].second] = ccans;
                        cnt++;
                    }
                    cans -= eqtt[j]*(2*j-1); 
                    cans += eqtt[j];
                    pegos += eqtt[j];
                }

                while(cnt < query[cc].size()){
                    ans[query[cc][cnt].second] = cans;
                    cnt++;
                }
            }
            else{
                if(graph[cc].size() >= lim) ebig.insert(-((int)graph[cc].size()));
                else eqtt[graph[cc].size()]++;

                esum++;
                osum += (2*(int)graph[cc].size())-1;

                int cnt = 0, pegos = 0;

                ll cans = esum;

                while(cnt < query[cc].size() && query[cc][cnt].first == 0){
                    // cout << "oi " << cans << endl;
                    ans[query[cc][cnt].second] = cans;
                    cnt++;
                }

                for(ll j: obig){
                    j = -j;
                    cans -= (2*j)-1; cans++;
                    while(cnt < query[cc].size() && pegos + 1 == query[cc][cnt].first){
                        ans[query[cc][cnt].second] = cans;
                        cnt++;
                    }
                    pegos++;
                }

                for(int j = lim-1; j > -1; j--){
                    while(cnt < query[cc].size() && pegos + oqtt[j] >= query[cc][cnt].first){
                        int aPegar = query[cc][cnt].first - (pegos);
                        ll ccans = cans - aPegar*(2*j-1) + aPegar;
                        ans[query[cc][cnt].second] = ccans;
                        cnt++;
                    }
                    cans -= oqtt[j]*(2*j-1); 
                    cans += oqtt[j];
                    pegos += oqtt[j];
                }

                while(cnt < query[cc].size()){
                    ans[query[cc][cnt].second] = cans;
                    cnt++;
                }
            }
        }

        for(int j: graph[cc]){
            if(j == last) continue;
            dfs(j,cc,d+1);
        }

        if(d){
            if(d%2){
                if(graph[cc].size() >= lim) obig.erase(obig.find(-((int)graph[cc].size())));
                else oqtt[graph[cc].size()]--;

                osum--;
                esum -= (2*(int)graph[cc].size())-1;
            }
            else{
                if(graph[cc].size() >= lim) ebig.erase(ebig.find(-((int)graph[cc].size())));
                else eqtt[graph[cc].size()]--;

                esum--;
                osum -= (2*(int)graph[cc].size())-1;
            }
        }

        return;
    };

    dfs(0,0,0);

    for(ll cc: ans){
        cout << cc << endl;
    }

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}