int n,m; 
vector<vector<int>> graph(0), revgraph(0); 
vector<int> visited(0), comp(0);
stack<int> stk1, stk2;
int compind = 0;

void dfs1(int curr){
    visited[curr] = 1;
    for(int j: graph[curr]){
        if(!visited[j]){
            dfs1(j);
        }
    }
    stk1.push(curr);
}

void dfs2(int curr){
    visited[curr] = 0;
    comp[curr] = compind;

    for(int j: revgraph[curr]){
        if(visited[j]){
            dfs2(j);
        }
    }
    stk2.push(curr);
}

void kosaraju(){
    visited.resize(n,0); comp.resize(n,0);

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs1(i);
    }

    while(!stk1.empty()){
        int i = stk1.top();
        stk1.pop();

        if(visited[i]){
            compind++;
            dfs2(i);
        }
    }
}