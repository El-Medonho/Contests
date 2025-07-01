#include "bits/stdc++.h"

using namespace std;

int INF = 100000;

template<class T> struct Dinic{
    struct Edge {int v,u; T cap,flow;};
    int m=0;
    vector<Edge> edges;
    vector<vector<int>> vec;
    vector<int> lv,pos;
    queue<int> fila;

    Dinic() {}

    Dinic(int n) : vec(n),lv(n),pos(n) {}

    void add_edge(int v, int u, T cap){
        edges.push_back({v,u,cap,0});
        edges.push_back({u,v,0,0});
        vec[v].push_back(m);
        vec[u].push_back(m+1);
        m+=2;
    }
    int bfs(int t)
    {
        while(!fila.empty())
        {
            int v = fila.front();
            fila.pop();
            for(int i:vec[v])
            {
                if(edges[i].cap - edges[i].flow<1) continue;
                if(lv[edges[i].u] != -1 ) continue;

                lv[edges[i].u] = lv[v] +1;
                fila.push(edges[i].u);
            }
        }
        return lv[t] !=-1;
    }

    T dfs(int v,int t , T menor)
    {
        if(!menor) return 0;
        if(v==t) return menor;

        for(int& j=pos[v]; j<(int)vec[v].size();j++)
        {
            int i=vec[v][j];
            int u = edges[i].u;

            if(lv[v]+1!=lv[u] || edges[i].cap-edges[i].flow<1) continue;

            T agr=dfs(u,t,min(menor,edges[i].cap-edges[i].flow));
            if(!agr) continue;
            edges[i].flow += agr;
            edges[i^1].flow-=agr;

            return agr;
        }
        return 0;
    }

    T max_flow(int s, int t)
    {
        T flow=0;
        while(1)
        {
            fill(lv.begin(),lv.end(),-1);

            lv[s]=0;
            fila.push(s);

            if(!bfs(t)) break;

            fill(pos.begin(), pos.end(), 0);

            while(T atual = dfs(s,t,INF)) flow += atual; //INF????
        }
        return flow;
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,r,l; cin >> n >> r >> l; r*=2; n = l;
    vector<pair<int,pair<int,int>>> positions;
    vector<pair<int,pair<int,int>>> positionsy;

    vector<unordered_set<int>> coluna(n);
    vector<unordered_set<int>> linha(n);

    for(int i=0;i<n;i++)
    {
        int a, b; cin >> a >> b; a--;b--;
        positions.push_back(make_pair(a,make_pair(b,i)));
        positionsy.push_back(make_pair(b,make_pair(a,i)));
    }
    sort(positions.begin(),positions.end());
    sort(positionsy.begin(),positionsy.end());

    for(int i=0;i<n;i++) // ver na horizontal
    {
        pair<int,pair<int,int>> pii = positions[i];
        for(int j=i+1;j<n;j++)
        {
            pair<int,pair<int,int>> pii2 = positions[j];
            if(pii.first != pii2.first) break;
            if(pii2.second.first - pii.second.first <= r)
            {
                linha[pii.second.second].insert(pii2.second.second);
                linha[pii2.second.second].insert(pii.second.second);
            }
        }
    }

    for(int i=0;i<n;i++) // ver na vertical
    {
        pair<int,pair<int,int>> pii = positionsy[i];
        for(int j=i+1;j<n;j++)
        {
            pair<int,pair<int,int>> pii2 = positionsy[j];
            if(pii.first != pii2.first) break;
            if(pii2.second.first - pii.second.first <= r)
            {
                coluna[pii.second.second].insert(pii2.second.second);
                coluna[pii2.second.second].insert(pii.second.second);
            }
        }
    }

    

    Dinic<int> fluxo((3*n)+2);

    int s = 3*n;
    int t = 3*n+1;

    set<pair<int,int>> edges_c;

    for(int i=0;i<n;i++)
    {
        fluxo.add_edge(s,i,1);
        if(coluna[i].size() == 0 || linha[i].size() == 0)
        {
            // << i << ' ' << t << endl;
            fluxo.add_edge(i,t,1);
            continue;
        }
        bool ld = false, cd=false;
        for(int j : coluna[i])
        {
            if(j < i) continue;
            if(edges_c.find(make_pair(i,j)) != edges_c.end()) continue;
            
                edges_c.insert(make_pair(i,j));
                fluxo.add_edge(j,n+i,1);
                if(!cd)
                {
                    fluxo.add_edge(i,n+i,1);
                    cd = true;
                }

        }
        for(int j : coluna[i])
        {
            for(int k : coluna[i])
            {
                if(k < j) continue;
                edges_c.insert(make_pair(j,k));
                
            }
        }

        for(int j : linha[i])
        {
            if(j < i) continue;
            if(edges_c.find(make_pair(i,j)) != edges_c.end()) continue;

            edges_c.insert(make_pair(i,j));

                fluxo.add_edge(j,2*n+i,1);
                if(!ld)
                {
                    fluxo.add_edge(i,2*n+i,1);
                    ld = true;
                }
                
        }
        for(int j : linha[i])
        {
            for(int k : linha[i])
            {
                if(k < j) continue;
                edges_c.insert(make_pair(j,k));
            }
        }

    }
    for(int i=n;i<3*n;i++)
    {
        fluxo.add_edge(i,t,1);
    }

    // fluxo.add_edge(s,1,1);
    // fluxo.add_edge(1,t,1);

    int fluxo_v = fluxo.max_flow(s,t);
    if(fluxo_v == n) cout << "YES\n";
    else cout << "NO\n";


    return 0;
}
