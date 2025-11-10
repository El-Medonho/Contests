#include "bits/stdc++.h"

#define endl '\n'
typedef long long ll;

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    pair<ll,ll> ans = {0,0};

    vector<ll> t(n);
    for(int i = 1; i < n; i++){
        cin >> t[i];
    }

    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> save(n+1, 0); 
    
    int mx = 0;
    function<void(int, int, int)> dfs = [&](int cc, int last, int layer){
        if(cc != 0){
            // cout << t[cc] << endl;
            save[layer] += t[cc];
            mx = max(mx, layer);
        }
        
        for(int j: graph[cc]){
            if(cc == 0){
                for(int i = 0; i <= mx; i++) {
                    // cout << save[i] << endl;
                    ans = max(ans, make_pair(save[i], -(ll)i));
                    save[i] = 0;
                }
                mx = 0;
            }
            if(j == last) continue;

            dfs(j, cc, layer+1);
        }

        if(cc == 0){
            for(int i = 0; i <= mx; i++) {
                // cout << save[i] << endl;
                ans = max(ans, make_pair(save[i], -(ll)i));
                save[i] = 0;
            }
            mx = 0;
        }
    };
    dfs(0,0,0);

    ll target = ans.first;

    int l = 1, r = n;
    int md = -1;
    int mn = n;
    ll cans = 0;

    function<void(int, int, int)> dfs2 = [&](int cc, int last, int layer){
        if(cc != 0){
            // cout << t[cc] << endl;
            save[layer] += t[cc];
            mx = max(mx, layer);
        }
        
        for(int j: graph[cc]){
            if(cc == 0){
                for(int i = 0; i <= mx; i++) {
                    // cout << save[i] << endl;
                    cans = max(cans, save[i]);
                    save[i] = 0;
                }
                mx = 0;
            }

            if(layer + md <= n){
                cans = max(cans, save[layer+md]);
                save[layer+md] = 0;
            }

            if(j == last) continue;

            dfs2(j, cc, layer+1);
        }

        if(cc == 0){
            for(int i = 0; i <= mx; i++) {
                // cout << save[i] << endl;
                cans = max(cans, save[i]);
                save[i] = 0;
            }
            mx = 0;
        }

        if(layer + md <= n){
            cans = max(cans, save[layer+md]);
            save[layer+md] = 0;
        }
    };

    while(l <= r){
        md = (l+r)/2;
        cans = 0;
        dfs2(0,0,0);

        if(cans == target){
            mn = min(mn, md);
            r = md-1;
        }
        else l = md+1;
    }


    cout << ans.first << ' ' << mn << endl;

    return 0;
}