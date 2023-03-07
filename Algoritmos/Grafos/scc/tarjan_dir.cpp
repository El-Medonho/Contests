int n,m;
vector<vii> graph(n); 
vii visiting(n, 0), lowlink(n, -1), depth(n, -1);
int tempo = 0;
stack<int> stk;

void tarjan(int curr){
    depth[curr] = lowlink[curr] = ++tempo;
    stk.push(curr);
    visiting[curr] = 1;

    for(int i: graph[curr]){
        if(lowlink[i] == -1){
            
            tarjan(i);
            lowlink[curr] = min(lowlink[curr], lowlink[i]);

        }else if(visiting[i] == 1){

            lowlink[curr] = min(lowlink[curr], depth[i]);

        }
    }

    if(depth[curr] == lowlink[curr]){
        int u = -1;
        while(u != curr){
            u = stk.top(); stk.pop();
            visiting[u] = 0;
        }
    }

    return;
}

bool tarjancaller(){
    for(int i = 0; i < n; i++){
        if(lowlink[i] == -1){
            tarjan(i);
        }
    }
    return true;
}