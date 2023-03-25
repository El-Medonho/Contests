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

vector<vii> graph;
vii weight(0);
int root = 0, tsz = 0;
vii ban(0);
int targetu, targetl;

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}

void upd2(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]=val;
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

int dfs(int curr, int last){
    weight[curr] = 0;
    for(int j: graph[curr]){
        if(j == last || ban[j]) continue;
        weight[curr] += dfs(j,curr);
    }
    return weight[curr]+1;
}

void centroid(int x){
    root = x;
    bool cont = true;
    dfs(root, -1);
    int last = -1;
    while(cont){
        cont = false;
        for(int j: graph[root]){
            if(j == last || ban[j]) continue;
            if(weight[j] >= (weight[x]+1)/2){
                last = root;
                cont = true;
                root = j;
                break;
            }
        }
    }
    return;
}

vii depth(0); vll occur(0);
queue<int> qw;
ll ans = 0;
int mxdepth = 0;

void dfs2(int curr, int last){
    if(depth[curr] <= targetu){
        ans += sum(targetu - depth[curr] + 1, occur); 
        ans -= sum(max(targetl - depth[curr],0), occur);
    } 
    
    mxdepth = max(depth[curr], mxdepth);
    qw.push(depth[curr]);
    for(int j :graph[curr]){
        if(j == last || ban[j]) continue;
        if((curr) == root) {
            while(!qw.empty()){
                upd(qw.front()+1, 1, occur); qw.pop();
            }
        }
        depth[j] = depth[curr] + 1;
        if(depth[j] <= targetu) dfs2(j,curr);
    }
}


int main(){
    fastio;

    int n; cin >> n >> targetl >> targetu; tsz = n;

    graph.resize(n);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ban.resize(n,0); depth.resize(n,0);  occur.resize(n+1,0); weight.resize(n,0);
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        fill(occur.begin(), occur.begin() + (mxdepth + 2), 0);
        upd2(min(mxdepth+2, targetu),0,occur);
        mxdepth = 0;

        int curr = q.front(); q.pop();

        centroid(curr);
        while(!qw.empty()) qw.pop();
        depth[root] = 0;
        dfs2(root, -1);

        ban[root] = 1;
        for(int j: graph[root]){
            if(!ban[j]) q.push(j);
        }
    }

    cout << ans << endl;


    return 0;
}