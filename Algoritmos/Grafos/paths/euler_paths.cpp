// para euler circuit o grau de todos os vertices tem q ser par
// para euler path o grau do inicio e do final tem q ser ímpar

int n,m;
vector<vector<pii>> graph(n);       //.f vizinho, .s id global da aresta
vii deg(0);
vii ans(0);
vii id(0);

int euler(){

    deg.resize(n); id.resize(m,0);

    for(int i = 0; i < n; i++){
        if(graph[i].size() % 2 == 1){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        deg[i] = graph[i].size();
    }

    stack<int> stk;
    stk.push(0);

    while(!stk.empty()){
        int v = stk.top();

        while(!graph[v].empty() && id[graph[v].back().s]){
            deg[v]--;
            graph[v].pop_back();
        }

        if(!deg[v]){
            ans.pb(v);
            stk.pop();
            continue;
        }
        
        pii u = graph[v].back();
        graph[v].pop_back();
        deg[v]--;
        id[u.s] = 1;
        stk.push(u.f);
    }

    if(ans.size() < m+1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i: ans) cout << i+1 << esp;
    cout << endl;

    return 1;
}