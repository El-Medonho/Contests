#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n,m;
vector<vector<int>> graph; vector<bool> is_on; vector<int> lowlink; vector<int> depth;
vector<int> repr; vector<int> numcomp; 
stack<int> stk; vector<set<int>> components; 
vector<pair<int,int>> ans;
int tempo = 0; int compi = 0;

void dfs(int curr){
    is_on[curr] = true;
    stk.push(curr);
    lowlink[curr] = depth[curr] = ++tempo;
    for(int next: graph[curr]){
        if(lowlink[next] == 0){
            dfs(next);
            lowlink[curr] = min(lowlink[curr], lowlink[next]);
        }
        else if(is_on[next]) lowlink[curr] = min(lowlink[curr], depth[next]);
    }

    if(lowlink[curr] == depth[curr]){
        int u = -1;
        components.push_back({});
        int save = stk.top();
        while(u != curr){
            u = stk.top();
            stk.pop();
            components[compi].emplace(u);
            repr[u] = save;
            is_on[u] = false;
        }
        compi++;
    }
}

void dfscaller(){
    for(int i = 0; i < n; i++){
        if(lowlink[i] == 0) dfs(i);
    }
}


int returnparent(int index){
    if(repr[index] == index) return index;
    else return repr[index] = returnparent(repr[index]);
}

void changeparent(int caller, int receiver){
    int a = returnparent(caller);
    int b = returnparent(receiver);

    repr[a] = b;
}

void searchgraph(){
    for(int i = 0; i < n; i++){
        int u = returnparent(i);
        for(int next: graph[i]){
            if(returnparent(next) == u) continue;
            ans.push_back({next,i});
            changeparent(i,next);
        }
    }
}

int saving = -1;
int cnt = 0;

int main(){
    fastio;

    cin >> n >> m;
    numcomp.resize(n,1); repr.resize(n,0); is_on.resize(n, false); lowlink.resize(n,0); depth.resize(n,0); graph.resize(n);
    for(int i = 0; i < n; i++) repr[i] = i;
    for(int i = 0; i < m; i++){
        int a,b; 
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }
    dfscaller();
    searchgraph();

    for(int i = 0; i < n; i++){
        if(repr[i] == i){
            if(cnt == 0){
                saving = i;
            } 
            else{
                ans.push_back({i,saving}); ans.push_back({saving,i});
            }
            cnt++;
        }
    }
    cout << ans.size() << endl;
    if(ans.size() > 0){
        for(pair<int,int> i: ans){
            cout << (i.f+1) << " " << (i.s+1) << endl;
        }
    }

    return 0;
}