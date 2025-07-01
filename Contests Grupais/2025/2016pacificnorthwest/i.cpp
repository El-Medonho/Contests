#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll resp = 0;
ll k;

void solve(vector<pair<ll,ll>> &casa){
    ll espaco = 0,sobra = 0;
    for(int i = casa.size()-1; i >= 0; i--){
        if(espaco >= casa[i].second){
            espaco -= casa[i].second;
        }
        else{
            casa[i].second -= espaco;
            resp += ((casa[i].second/k)*(casa[i].first*2));
            sobra = casa[i].second% k;
            if(sobra >0){
                espaco = k-sobra;
                resp += (casa[i].first*2);
            }
            else espaco = 0;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n >> k;

    vector<pair<ll,ll>> casa_d,casa_e;

    for(int i = 0; i < n; i++){
        ll x, m; cin >> x >> m;

        if(x > 0) casa_d.push_back(make_pair(x,m));
        else casa_e.push_back(make_pair(abs(x),m));
    }

    sort(casa_d.begin(), casa_d.end());
    sort(casa_e.begin(), casa_e.end());

    solve(casa_d); solve(casa_e);

    cout << resp << '\n';

    return 0;
}