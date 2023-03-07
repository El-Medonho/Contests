//O(V.E²)
int n,m;
vector<vector<pii>> graph(0);
vii cap(0);
vii rescap(0);

ll bfs(int s, int t, vector<pii> &parent){
    fill(parent.begin(), parent.end(), make_pair(-1,-1));
    parent[s] = {-2,-2};

    queue<pll> q;
    q.push({s,INFL});

    while(!q.empty()){
        int curr = q.front().f;
        int flow = q.front().s;
        q.pop();

        for(pii g: graph[curr]){
            int j = g.f;
            if(parent[j].f == -1 && rescap[g.s]){
                parent[j] = {curr,g.s};
                ll newflow = min(flow, rescap[g.s]);
                if(j == t) return newflow;
                q.push({j, newflow});
            }
        }
    }

    return 0;
}

ll maxflow(int s, int t){
    ll flow = 0;
    vector<pii> parent(n);
    int newflow;

    while(newflow = bfs(s,t,parent)){
        flow += newflow;
        int curr = t;
        while(curr != s){
            int prev = parent[curr].f;
            int edge = parent[curr].s;

            ll currflow = newflow;
            if(edge % 2 == 1) {currflow*=(-1); edge--; };

            rescap[edge] -= currflow;
            rescap[edge+1] += currflow;

            curr = prev;
        }
    }
    return flow;
}

void setgraph(){
    cap.resize(2*m);
    graph.resize(n);

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].pb({b,i*2});
        graph[b].pb({a,i*2+1});
        cap[2*i] = c;
        cap[2*i+1] = 0;
    }

    rescap = cap;
}



//-------------------------------------------------------------------------------------------------

//O(V.E²)
int n,m;
vector<vii> graph(0);
vector<vii> cap(0);
vector<vii> rescap(0);

ll bfs(int s, int t, vii &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pll> q;
    q.push({s,INFL});

    while(!q.empty()){
        int curr = q.front().f;
        int flow = q.front().s;
        q.pop();

        for(int j: graph[curr]){
            if(parent[j] == -1 && rescap[curr][j]){
                parent[j] = curr;
                ll newflow = min(flow, rescap[curr][j]);
                if(j == t) return newflow;
                q.push({j, newflow});
            }
        }
    }

    return 0;
}

ll maxflow(int s, int t){
    ll flow = 0;
    vii parent(n);
    int newflow;

    while(newflow = bfs(s,t,parent)){
        flow += newflow;
        int curr = t;
        while(curr != s){
            int prev = parent[curr];

            ll currflow = newflow;

            rescap[prev][curr] -= currflow;
            rescap[curr][prev] += currflow;

            curr = prev;
        }
    }
    return flow;
}

void setgraph(){
    cap.resize(n, vii(n,0));
    graph.resize(n);

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
        cap[a][b] = c;
        cap[b][a] = 0;
    }

    rescap = cap;
}