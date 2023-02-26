int tempo = 0, comp_ind; 
vector<vector<int>> graph(0); vector<int> lowlink(0), depth(0);
stack<int> stk;

int dfs(int curr){
    is_on[curr] = true;
    lowlink[curr] = depth[curr] = ++tempo;
    stk.emplace(curr);

    for(int next: graph[curr]){
        if(lowlink[next] == -1){
            dfs(next);
            lowlink[curr] = min(lowlink[curr], lowlink[next]);
        }
        else if(is_on[next]) lowlink[curr] = min(depth[next], lowlink[curr]);
    }

    if(depth[curr] == lowlink[curr]){
        componentes.pb({}); comp_ind++;
        int u = -1;
        while(u != curr){
            u = stk.top();
            component_by_point[u] = comp_ind;
            stk.pop();
            componentes[comp_ind].pb(u);
            is_on[u] = false;
        }
    }
    return 0;
}