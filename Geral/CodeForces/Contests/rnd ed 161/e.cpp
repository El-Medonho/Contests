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

struct qu{
    int i,rnd,l,r;
    qu(int x, int rn, int a, int b){
        i = x; rnd = rn; l = a; r = b;
    }
};

signed solve(){

    int n; cin >> n;
    vector<ll> arr(n+2, 0), hp(n+2, 1e18);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> hp[i];
    }

    vector<ll> l(n+2, 0), r(n+2, n+1);
    vector<int> dead(n+2, 1e9);

    for(int i = 1; i <= n; i++){
        l[i] = i-1;
        r[i] = i+1;
    }

    queue<qu> qw;

    vector<int> ans(n+2, 0);

    function<int(int)> fl, fr;

    fl = [&](int x){
        if(dead[l[x]] == 1e9 || l[x] == x) return l[x];
        else return l[x] = fl(l[x]);
    };

    fr = [&](int x){
        if(dead[r[x]] == 1e9 || r[x] == x) return r[x];
        else return r[x] = fr(r[x]);
    };

    // vector<int> inqueue(n, -1);

    for(int i = 1; i <= n; i++){
        if(arr[l[i]] + arr[r[i]] > hp[i]){
            qw.push(qu(i,0,l[i],r[i]));
            // inqueue[i] = 0;
        }
    }


    while(!qw.empty()){
        auto[i, rnd, a, b] = qw.front(); qw.pop();

        if(rnd == 1){
            int h = 4;
        }

        if(rnd >= n) break;

        if(i == 0 || i == n+1) continue; 
        
        if(dead[a] < rnd || dead[b] < rnd || dead[i] <= rnd) continue;

        if(arr[a] + arr[b] > hp[i]){
            dead[i] = rnd;
            ans[rnd]++;

            l[i] = fl(i); 
            r[i] = fr(i);
            
            if(r[i] != 0 && r[i] != n+1) l[r[i]] = l[i];
            if(l[i] != 0 && l[i] != n+1) r[l[i]] = r[i];
            
            if(l[i] != 0 && l[i] != n+1){
                int x = l[i];
                if(arr[l[x]] + arr[r[x]] > hp[x]){
                    qw.push(qu(x, rnd+1, l[x], r[x]));
                }
            }
            if(r[i] != 0 && r[i] != n+1){
                int x = r[i];
                if(arr[l[x]] + arr[r[x]] > hp[x]){
                    qw.push(qu(x, rnd+1, l[x], r[x]));
                }
            }
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;

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