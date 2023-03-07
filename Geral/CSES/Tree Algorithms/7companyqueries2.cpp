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

int n,q;
vector<vii> graph(0), up(0);
vii parent(0), depth(0);

void getdepth(){
    queue<int> qw;
    qw.push(0);

    while(!qw.empty()){
        int curr = qw.front(); qw.pop();
        for(int j: graph[curr]){
            qw.push(j);
            depth[j] = depth[curr]+1;
        }
    }
    return;
}

void bl(){
    for(int i = 0; i < n; i++){
            up[i][0] = parent[i];
    }

    for(int j = 1; j < 20; j++){
        for(int i = 0; i < n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    return;
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a,b);
        int k = depth[b] - depth[a];

        for(int i = 19; i > -1; i--){
            if(k & (1<<i)){
                b = up[b][i];
            }
        }

        if(a == b){
            return a;
        }

        pii last = {a,b}; int matching = INF;
        for(int i = 19; i > -1; i--){
            a = up[a][i]; b = up[b][i];
            if(a == b){
                matching = a;
                a = last.f; b = last.s;
            }else{
                last = {a,b};
            }
        }
        return matching;
}


int main(){
    fastio;

    cin >> n >> q;
    graph.resize(n); parent.resize(n,0); depth.resize(n,0);
    up.resize(n, vii(20,0));

    for(int i = 1; i < n; i++){
        int a; cin >> a; a--;
        parent[i] = a;
        graph[a].pb(i);
    }

    getdepth();
    bl();

    while(q--){
        int a,b; cin >> a >> b; a--; b--;

        cout << lca(a,b)+1 << endl;
    }

    return 0;
}