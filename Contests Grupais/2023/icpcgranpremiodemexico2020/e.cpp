// ░░░░░░░░░░░░▄▄▄█████████▄▄▄░░░░░░░░░░░░
// ░░░░░░░░▄▄██████▀▀▀▀▀▀▀██████▄▄░░░░░░░░
// ░░░░░░▄████▀▀░░░░░░░░░░░░░▀▀████▄░░░░░░
// ░░░░▄███▀░░░░░░░░░░░░░░░░░░░░▀▀███▄░░░░
// ░░▄███▀░░░░░░░░░░░░░░░░░░░░░░░░░████░░░
// ░▄███▀░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░▀███░░
// ░███░░░░░░█████▄░░░░░░░░░░░░░░░░░░▀███░
// ███▀░░░░░░██████░░░░░░░░░░░░░░░░░░░███▄
// ███░░░░░░░█████▀░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░████▄░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░▀███▄░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░░░█████▄░░░▄███▄▄░░░░░░▄███
// ▀███░░░░░░░░░░░░▀████████████░░░░░░███░
// ░███▄░░░░░░░░░░░░░▀▀████████▀░░░░░███▀░
// ░░████░░░░░░░░░░░░░░░░░▀▀▀░░░░░░▄███▀░░
// ░░███▀░░░░░░░░░░░░░░░░░░░░░░░░░▄███▀░░░
// ░▄███░░░░▄▄░░░░░░░░░░░░░░░░░▄████▀░░░░░
// ▄███▄▄███████▄▄▄░░░░░░░▄▄▄█████▀░░░░░░░
// ███████▀▀▀▀▀███████████████▀▀░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ▒█░░▒█ █░░█ █▀▀█ ▀▀█▀▀ █▀▀ ░█▀▀█ █▀▀█ █▀▀█░ 
// ▒█▒█▒█ █▀▀█ █▄▄█ ░░█░░ ▀▀█ ▒█▄▄█ █░░█ █░░█░
// ▒█▄▀▄█ ▀░░▀ ▀░░▀ ░░▀░░ ▀▀▀ ▒█░▒█ █▀▀▀ █▀▀▀░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

int main(){
    fastio;

    ll n,m,q, root; cin >> n >> m >> q;

    vll occur(n+1,0), parent(n+1,0);
    vector<vll> children(n+1);

    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        if(a == 0) root = i+1;
        occur[a]++;
        parent[i+1] = a;
        children[a].pb(i+1);
    }

    vector<pll> aaa(n+1,{0,0});

    while(m--){
        ll op, id, bb; cin >> op >> id >> bb;
        if(op&1) aaa[id].f+=bb;
        else aaa[id].s+=bb;
    }

    queue<ll> qw;
    for(ll i = 0; i <= n; i++) if(!occur[i]) qw.push(i);
    fill(occur.begin(), occur.end(), 0); occur[0] = 1;

    while(!qw.empty()){
        ll id = qw.front(); qw.pop();
        aaa[id].f+= aaa[id].s;
        aaa[parent[id]].s+=aaa[id].s;
        occur[parent[id]]++;
        if(occur[parent[id]] == children[parent[id]].size()) qw.push(parent[id]);
    }

    vector<pll> ind(n+1, {0,0});
    vll seq(n,0); ll sum = 0;
    ll hh = -1;
    function<void(ll)> dfs;
    dfs = [&](ll curr){
        ind[curr].f = ++hh;
        sum+=aaa[curr].f;
        seq[hh] = sum;

        for(ll j: children[curr]){
            dfs(j);
        }
        ind[curr].s = hh;
        return;
    };

    dfs(root);

    while(q--){
        ll op; cin >> op;
        ll h; cin >> h;
        if(op & 1){
            cout << aaa[h].f << endl;
        }else{
            cout << seq[ind[h].s] - seq[ind[h].f] + aaa[h].f << endl;
        }
    }

    return 0;
}