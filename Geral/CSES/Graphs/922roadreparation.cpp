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
vii pai(0), peso(0);
set<int> pais;

int ff(int x){
    if(pai[x]==x) return x;
    return pai[x]=ff(pai[x]);
}

void uu(int x, int y){
    x=ff(x), y=ff(y);
    if(x==y) return;
    if(peso[y]>peso[x]) swap(x, y);
    pais.erase(y);
    pai[y]=x;
    peso[x]+=peso[y];
}

void init(){
    for(int i=0; i<n; i++){
        pai[i]=i;
        pais.insert(i);
        peso[i]=1;
    }
}

int main(){
    fastio;

    int m; cin >> n >> m;

    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        pq.push(make_pair(c, make_pair(--a, --b)));
    }

    pai.resize(n,0); peso.resize(n,0);
    init();

    ll cost = 0;
    while(!pq.empty()){
        int c = pq.top().f, a = pq.top().s.f, b = pq.top().s.s;
        pq.pop();

        a == ff(a); b = ff(b);
        if(pai[a] == pai[b]) continue;

        uu(a,b);
        cost += c;

        if(pais.size() == 1) break;
    }

    if(pais.size() > 1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << cost << endl;
    }

    return 0;
}