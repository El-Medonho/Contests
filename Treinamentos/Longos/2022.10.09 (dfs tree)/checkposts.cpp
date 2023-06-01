#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define pb push_back
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

ll n,m;
ll tempo = 0;
ll indiceg = -1;
vector<ll> costs, over, lowlink, depth;
vector<vector<ll>> compconexas, graph;
stack<ll> stk;

ll tarjan(ll curr){
    over[curr] = 0;
    depth[curr] = lowlink[curr] = ++tempo;
    stk.push(curr);

    for(ll next: graph[curr]){
        if(lowlink[next] == -1){
            tarjan(next);
            lowlink[curr] = min(lowlink[curr], lowlink[next]);
        }
        else if (over[next] == 0) lowlink[curr] = min(lowlink[curr], depth[next]);
    }

    if (lowlink[curr] == depth[curr]){
        ll u = -1;
        indiceg++;
        compconexas.pb({});

        while(u != curr){
            u = stk.top();
            stk.pop();
            over[u] = 1;
            compconexas[indiceg].pb(u);
        }
    }
    return 0;
}

ll dfscaller(){
    for(ll i = 0; i < n; i++){
        if(lowlink[i] == -1) tarjan(i);
    }
    return 0;
}

ll possibilities = 1; ll coins = 0;

void coinfinder(){
    for(ll g = 0; g < compconexas.size(); g++){
        ll record = INFL; ll occur = 1;
        for(ll curr: compconexas[g]){
            if(costs[curr] < record){ record = costs[curr]; occur = 1;}
            else if(costs[curr] == record) occur++;
        }
        possibilities = mod(possibilities*occur, MOD);

        coins += record;
    }
}


int main(){
    fastio;
    cin >> n;
    costs.resize(n);
    graph.resize(n);
    over.resize(n,1);
    depth.resize(n,-1); lowlink.resize(n,-1);

    for(ll i = 0; i < n; i++){
        ll a = 0;
        cin >> a;
        costs[i] = a;
    }

    cin >> m;

    for(ll i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        graph[a-1].pb(b-1);
    }

    //---------------------------------------------------

    dfscaller();
    coinfinder();

    possibilities %= MOD;

    cout << coins << " " << possibilities << endl;
    return 0;
}