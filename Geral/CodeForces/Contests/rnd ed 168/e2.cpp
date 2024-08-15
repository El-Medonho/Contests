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
    
    int n,q; cin >> n >> q;

    int h = 600;
    int hh = 0;

    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    vector<pair<int,int>> qu(q), qc(q, {-1,1});

    vector<int> persum(0), perpre(0), ans(q, 0);

    vector<vector<int>> perx(n+1), perx2(n+1);

    for(int qw = 0; qw < q; qw++){
        int i,x; cin >> i >> x;
        i--;

        if(arr[i]*x > i){
            ans[qw] = 1;
            continue;
        }

        qu[qw] = {i, x};

        if(arr[i] > h){
            persum.push_back(qw);
            perx2[x].push_back(qw);
            hh = max(hh, x+2);
        }

        else{
            perpre.push_back(qw);
            perx[x].push_back(qw);
        }
    }


    vector<int> pre(n+1, -1);

    for(int lvl = 1; lvl <= h+3; lvl++){
        vector<int> sum(n, 0);
        for(int i = 0; i < n; i++){
            if(i > 0) sum[i] = sum[i-1];
            if(lvl <= arr[i]) sum[i]++;
        }

        vector<int> first(n+1, n);

        for(int i = n-1; i > -1; i--) first[sum[i]] = i;

        for(int x = 1; x <= n; x++){
            int base; bool ok = true;
            if(lvl == 1) base = 0;
            else if(pre[x] == n){
                pre[x] = n;
                ok = false;
            }
            else base = sum[pre[x]];

            if(ok){
                base += x;

                if(base > n || first[base] == n) pre[x] = n;
                else pre[x] = first[base];
            }


            for(int i: perx[x]){
                if(qc[i].first >= qu[i].first) continue;

                qc[i].first = pre[x];
                if(qc[i].first >= qu[i].first) continue;

                qc[i].second++;
            }
        }
    }

    for(int i: perpre){
        if(qc[i].second <= arr[qu[i].first]) ans[i] = 1;
        else ans[i] = 0;
    }


    for(int j = 1; j <= min(hh+3, n); j++){
        vector<int> lvl(n, 1);
        int cc = 0, clvl = 1;
        for(int i = 0; i < n; i++){
            if(i != 0) lvl[i] = clvl;
            if(arr[i] >= lvl[i]) cc++;
            if(cc >= j) {clvl++; cc = 0;}
        }

        for(int i: perx2[j]){
            if(lvl[qu[i].first] <= arr[qu[i].first]) ans[i] = 1;
            else ans[i] = 0;
        }
    }

    for(int i = 0; i < q; i++){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }

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