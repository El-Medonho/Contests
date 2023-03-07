int n;
vector<vii> graph(0), up(0);
vii parent(0), depth(0);

void dfs(int curr, int last){
    for(int j: graph[curr]){
        if(last == j) continue;
        depth[j] = depth[curr]+1;
        parent[j] = curr;
        dfs(j,curr);
    }
    return;
}

void dfscall(){

    depth.resize(n,0);
    parent.resize(n,0);
    dfs(0,-1);

    return;
}

// void bfs(){    //useful if you already have the parents
//     depth.resize(n,0);
//     queue<int> qw;
//     qw.push(0);

//     while(!qw.empty()){
//         int curr = qw.front(); qw.pop();
//         for(int j: graph[curr]){
//             qw.push(j);
//             depth[j] = depth[curr]+1;
//         }
//     }
//     return;
// }

void bl(){
    up.resize(n, vii(32,0));
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