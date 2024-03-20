#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define INF (1e9 + 500)
#define pii pair<int,int>
#define pb push_back
typedef long long ll;

struct Hopcroft{ //Hopcroft hop(n, m); O(sqrt(V)*E)
    int n, m;
    vector<vector<int>> vec;
    vector<int> pairn, pairm, dist;
    queue<int> fila;

    Hopcroft(int n, int m) : n(n), m(m){
        vec.resize(n+1);
        dist.resize(n+1);
        pairn.resize(n+1);
        pairm.resize(m+1);
    }

    void add_edge(int v, int u) { 
        vec[v+1].pb(u+1);
    }

    int bfs(){
        for(int i=1; i<=n; i++){
            if(!pairn[i]){
                dist[i]=0;
                fila.push(i);
            }else{
            dist[i]=INF;
            }
        }
        dist[0]=INF;

        while(!fila.empty()){
            int v=fila.front();
            fila.pop();
            if(dist[v]<dist[0]){
                for(int i:vec[v]){
                    if(dist[pairm[i]]==INF){
                        dist[pairm[i]]=dist[v]+1;
                        fila.push(pairm[i]);
                    }
                }
            }
        }
        return dist[0]!=INF;
    }

    int dfs(int v){
        if(v){
            for(int i:vec[v]){
                if(dist[pairm[i]]==dist[v]+1){
                    if(dfs(pairm[i])){
                        pairm[i]=v;
                        pairn[v]=i;
                        return 1;
                    }
                }
            }
            dist[v]=INF;
            return 0;
        }
        return 1;
    }

    int max_bip(){
        int resp=0;
        while(bfs()){
            for(int i=1; i<=n; i++){
                if(!pairn[i] && dfs(i)) resp++;
            }
        }
        return resp;
    }

    vector<pii> pairs(){
        vector<pii> ans;
        for(int i=1; i<=n; i++){
            if(pairn[i]) ans.pb({pairn[i]-1, i-1});
        }
        return ans;
    }
};

int main(){
    fastio;

    int n; cin >> n;
    vector<vector<vector<int>>> coord(27, vector<vector<int>> (27, vector<int> (27, -1)));
    vector<string> sss(n);
    int cnt = -1;

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        vector<int> a(3, 0);
        for(int i = 0; i < str.size(); i++){
            a[i] = (str[i] - 'a') + 1;
        }
        coord[a[0]][a[1]][a[2]] = ++cnt;
        sss[cnt] = str;
    }

    int r; cin >> r;

    vector<int> max_position(n,0), vss(n,0);
    vector<vector<int>> conn(n, vector<int>(0)), corr(n, vector<int>(n,0));
    while(r--){
        int hh, place; cin >> hh >> place; place--;
        vss[place]++;
        while(hh--){
            string str; cin >> str;
            vector<int> a(3, 0);
            for(int i = 0; i < str.size(); i++){
                a[i] = (str[i] - 'a') + 1;
            }
            max_position[coord[a[0]][a[1]][a[2]]] = max(place, max_position[coord[a[0]][a[1]][a[2]]]); 
            corr[place][coord[a[0]][a[1]][a[2]]]++;          
        }
    }

    Hopcroft matching(n,n);

    for(int i = 0; i < n; i++){
        if(corr[max_position[i]][i] == vss[max_position[i]])matching.add_edge(i, max_position[i]);
    }

    for(int i = 0; i < n; i++){
        if(!vss[i]){
            for(int j = 0; j < n; j++){
                if(max_position[j] < i) matching.add_edge(j,i);
            }
        }
    }

    matching.max_bip();
    vector<pii> ans = matching.pairs();

    sort(ans.begin(), ans.end());

    for(int i = 0; i < n; i++){
        cout << sss[ans[i].second] << " ";
    }
    cout << endl;

    return 0;
}