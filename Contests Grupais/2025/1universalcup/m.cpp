#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int n, m;

struct bm_t {
    int N, M, T;
    vector<vector<int> > adj;
    vector<int> match, seen;
    bm_t(int a, int b) : N(a), M(a+b), T(0), adj(M), match(M, -1), seen(M, -1) {}

    void add_edge(int a, int b) { adj[a].push_back(b+N); }

    bool dfs(int cur){
        if(seen[cur] == T) return false;
        seen[cur] = T;
        for(int nxt:adj[cur]) if(match[nxt]==-1){
            match[nxt] = cur, match[cur] = nxt;
            return true;
        }
        for(int nxt:adj[cur]) if(dfs(match[nxt])){
            match[nxt] = cur, match[cur] = nxt;
            return true;
        }
        return false;
    }
    int solve(){
        int res = 0;
        for(int cur = 1; cur;){
            cur = 0; ++T;
            for(int i=0; i<N; i++){
                if(match[i] == -1) cur+=dfs(i);
            }
            res+=cur;
        }
        return res;
    }
};

struct Kosa {
    int n;
    vector<int> memo, comp, st, grau, cor;
    vector<vector<int> > vec, rvec, scc;

    Kosa (int n) : n(n), memo(n), comp(n, -1), vec(n), rvec(n), scc(n), grau(n), cor(n, -1) {}

    void add_edge(int a, int b){
        vec[a].push_back(b);
        rvec[b].push_back(a);
    }

    void dfs(int x){
        memo[x]=1;
        for(int i:vec[x]){
            if(!memo[i]) dfs(i);
        }
        st.push_back(x);
    }

    void dfs2(int x, int c){
        comp[x]=c;
        for(int i:rvec[x]){
            if(comp[i] == -1) dfs2(i, c);
        }
    }

    void dfs3(int x, int c){
        cor[x] = c;
        for(int i:scc[x]){
            if(cor[i]==-1) dfs3(i, c);
        }
    }

    void build(){
        int cont = 0;
        for(int i=0; i<n; i++){
            if(!memo[i]) dfs(i);
        }
        reverse(st.begin(), st.end());
        for(int i:st){
            if(comp[i] == -1) dfs2(i, cont++);
        }
        auto bm = bm_t(cont, cont);
        for(int i=0; i<n; i++){
            for(int j:vec[i]){
                if(comp[i] == comp[j]) continue;
                bm.add_edge(comp[i], comp[j]);
            }
        }
        int color = 0;
        int how_many = cont - bm.solve();
        for(int i=0; i<cont; i++){
            if(bm.match[i+cont] == -1){
                int cur = i;
                cor[cur] = color;
                while(bm.match[cur]>=0){
                    cur = bm.match[cur] - cont;
                    cor[cur] = color;
                }
                color++;
            }
        }
        for(int i=0; i<n; i++){
            cout << cor[comp[i]]+1 << ' ';
        }
        cout << endl;
    }

};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    auto kosa = Kosa(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        kosa.add_edge(a, b);
    }
    
    kosa.build();

    return 0;
}