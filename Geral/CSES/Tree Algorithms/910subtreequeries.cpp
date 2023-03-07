#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
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

int n;
vector<vii> graph(0), up(0);
vll arr(1,0), value(0);
vector<pii> ind(0);
int tempo = 0;

void dfs(int curr, int last){
    arr.pb(value[curr]);
    ind[curr].f = ++tempo;
    for(int j: graph[curr]){
        if(last == j) continue;
        dfs(j,curr);
    }
    ind[curr].s = tempo;
    return;
}

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

int main(){
    fastio;

    int m; cin >> n >> m;

    value.resize(n,0);
    ind.resize(n);
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }

    graph.resize(n);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(0,-1);
    vll bit(n+1,0);

    for(int i = 1; i <= n; i++){
        upd(i,arr[i],bit);
    }

    while(m--){
        int op; cin >> op;
        if(op == 1){
            int s,x; cin >> s >> x; s--;
            ll diff = x - value[s];
            value[s] = x;
            upd(ind[s].f, diff, bit);
        }else{
            int a; cin >> a; a--;
            ll ans = sum(ind[a].s, bit);
            if(a != 0) ans -= sum(ind[a].f-1, bit);
            cout << ans << endl;
        }
    }

    return 0;
}