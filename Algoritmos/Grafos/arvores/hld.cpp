//esse algoritmo precisa do uso de segtree
//O(q.log²n)

vii weight(0), depth(0), parent(0);

int dfs(int curr, int last){
    weight[curr] = 1;
    
    for(int j: graph[curr]){
        if(last == j) continue;
        depth[j] = depth[curr]+1;
        parent[j] = curr;
        weight[curr] += dfs(j,curr);
    }
    return weight[curr];
}

void dfscall(){

    depth.resize(n,0);
    parent.resize(n,0);
    weight.resize(n,0);
    dfs(0,-1);

    return;
}

vii ind(0),tp(0);
int tempo = 0;

void hld(int curr, int last, int top){
    arr[tempo] = value[curr];
    upd(tempo, value[curr]);
    ind[curr] = tempo++;
    tp[curr] = top;

    int wt_id = -1, wt_val = -1;

    for(int j: graph[curr]){
        if(j == last) continue;
        if(weight[j] > wt_val){
            wt_val = weight[j];
            wt_id = j;
        }
    }

    if(wt_id == -1) return;

    hld(wt_id, curr, top);
    
    for(int j: graph[curr]){
        if(j == last || j == wt_id) continue;
        hld(j,curr,j);
    }
}

void hldcall(){
    ind.resize(n); tp.resize(n);
    hld(0,-1,0);
}

ll path(int a, int b){
    ll ans = -INFL;
    while(tp[a] != tp[b]){
        if(depth[tp[a]] < depth[tp[b]]) swap(a,b);
        ans = max(ans, query(ind[tp[a]],ind[a]));
        a = tp[a];
        a = parent[a];
    }

    if(depth[a] < depth[b]) swap(a,b);
    ans = max(ans, query(ind[b],ind[a]));

    return ans;
}