vii weight(0);
int root = 0, tsz = 0;

int dfs(int curr, int last){
    for(int j: graph[curr]){
        if(j == last) continue;
        weight[curr] += dfs(j,curr);
    }
    return weight[curr]+1;
}

void centroid(){
    bool cont = true;
    weight.resize(tsz,0);
    dfs(root, -1);
    int last = -1;
    while(cont){
        cont = false;
        for(int j: graph[root]){
            if(j == last) continue;
            if(weight[j] >= tsz/2){
                last = root;
                cont = true;
                root = j;
                break;
            }
        }
    }
    return;
}