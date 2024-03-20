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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}
ll sum(int ind, vector<ll> &bit){         //O(logn)
    ll ans=0;
    while(ind){
        ans+=bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

signed main(){
    fastio;

    int n,q; cin >> n >> q;

    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    vector<ll> bit(1, 0);

    int tempo = 1;

    vector<vector<int>> graph(n);
    vector<pair<int,int>> timing(n, {0,0});

    vector<int> subord(n,0);

    for(int i = 0; i < n-1; i++){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        subord[b]++;
    }

    int in = -1;

    for(int i = 0; i < n; i++){
        if(subord[i] == 0) in = i;
    }

    vector<pair<int,int>> queries(q);

    for(int i = 0; i < q; i++){
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--;
    }

    vector<int> filhos(n,1);

    function<void(int,int)> dfs;

    dfs = [&](int cc, int last){

        bit.push_back(0);
        timing[cc].first = tempo++;

        for(int j: graph[cc]){
            if(j == last) continue;
            dfs(j, cc);
            filhos[cc] += filhos[j];
        }

        bit.push_back(0);
        timing[cc].second = tempo++;

        return;
    };

    dfs(in,-1);

    vector<int> ans(n, -1);

    vector<vector<int>> meios(q);

    bool ok = 1;

    int l[n], r[n];

    for(int i = 0; i < n; i++){
        l[i] = 0; r[i] = q-1;
        meios[(l[i]+r[i]) / 2].push_back(i);
    }

    while(ok){
        ok = 0;

        for(int g = 0; g < q; g++){
            int x = queries[g].first;
            ll val = queries[g].second;

            upd(timing[x].first, val%filhos[x], bit);
            upd(timing[x].first + 1, -val%filhos[x], bit);
            
            upd(timing[x].first, val/filhos[x], bit);
            upd(timing[x].second, -val/filhos[x], bit);

            while(meios[g].size()){
                ok = 1;

                int cc = meios[g].back();
                meios[g].pop_back();

                ll h = sum(timing[cc].first, bit);

                if(h >= arr[cc]){
                    ans[cc] = g+1;
                    r[cc] = g-1;
                }else{
                    l[cc] = g+1;
                }

                if(l[cc] <= r[cc]) meios[ (l[cc]+r[cc]) / 2 ].push_back(cc);
            }
        }

        fill(bit.begin(), bit.end(), 0);
    }

    for(int i: ans) cout << i << '\n';

    return 0;
}