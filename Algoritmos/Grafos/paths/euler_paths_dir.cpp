int n,m;
vector<vector<pii>> graph(n);       //.f vizinho, .s id global da aresta

vii degin(0);
vii degout(0);
vii ans(0);
vii id(0);

int eulerdir(){

    degin.resize(n,0); degout.resize(n,0); id.resize(m,0);

    for(int i = 0; i < n; i++){
        for(pii j: graph[i]){
            degout[i]++;
            degin[j.f]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(i == 0 || i == n-1) {
            if( (i == 0 && degout[i] - degin[i] != 1) || (i == n-1 && degin[i] - degout[i] != 1) ){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            continue;
        }
        if(degin[i] != degout[i]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    stack<int> stk;
    stk.push(0);

    while(!stk.empty()){
        int v = stk.top();

        while(!graph[v].empty() && id[graph[v].back().s]){
            degout[v]--;
            graph[v].pop_back();
        }

        if(!degout[v]){
            ans.pb(v);
            stk.pop();
            continue;
        }
        
        pii u = graph[v].back();
        graph[v].pop_back();
        degout[v]--;
        id[u.s] = 1;
        stk.push(u.f);
    }

    reverse(ans.rbegin(), ans.rend());

    if(ans.size() < m+1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i: ans) cout << i+1 << esp;
    cout << endl;

    return 1;
}