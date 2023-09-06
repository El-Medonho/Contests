// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

template<typename T, typename Cmp=less<T>>
struct rmq_t : private Cmp {
	int N = 0;
	vector<vector<T>> table; 
	const T& min(const T& a, const T& b) const { return Cmp::operator()(a, b) ? a : b; }
	rmq_t() {}
	rmq_t(const vector<T>& values) : N(int(values.size())), table(__lg(N) + 1) {
		table[0] = values;
		for (int a = 1; a < int(table.size()); ++a) {
			table[a].resize(N - (1 << a) + 1);
			for (int b = 0; b + (1 << a) <= N; ++b) 
				table[a][b] = min(table[a-1][b], table[a-1][b + (1 << (a-1))]); 
		}
	}
	T query(int a, int b) const { 
		int lg = __lg(b - a);
		return min(table[lg][a], table[lg][b - (1 << lg) ]);
	}
};

struct lca_t {
	int T = 0;
	vector<int> time, path, walk;
	rmq_t<int> rmq;
	lca_t(vector<vector<int>> &edges) : time(int(edges.size())), 
	rmq((dfs(edges,0,-1), walk)) {}
	void dfs(vector<vector<int>> &edges, int v, int p) {
		time[v] = T++;
		for(int u : edges[v]) if (u != p) {
			path.push_back(v), walk.push_back(time[v]);
			dfs(edges, u, v);
		}
	}
	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
};

signed main(){
    fastio;

    int n; cin >> n;

    vector<vector<pair<int,int>>> graph(n);
    vector<vector<int>> edges(n), rel(n);
    
    vector<int> cor(n,-1);
    for(int a = 0; a < n; a++) {
        cin >> cor[a]; cor[a]--;
        rel[cor[a]].push_back(a);
    }

    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }

    //-------------------------------

    lca_t lca(edges);

    vector<ll> euler(1, 0);
    vector<pair<int,int>> ver(n, {-1,-1}), ar(n-1, {-1,-1});
    int time = 1;
    
    function<void(int, int)> dfs;

    dfs = [&](int cc, int last){

        euler.push_back(0);
        ver[cc].first = time++;

        for(auto [j,a]: graph[cc]){
            if(j == last) continue;
            
            euler.push_back(0);
            ar[a].first = time++;

            dfs(j, cc);

            ar[a].second = time;
        }

        ver[cc].second = time;
    };

    dfs(0, -1);

    euler.push_back(0); time++;

    //-----------------------------  reroot

    vector<ll> ans(n-1, 0);

    int magic = 310;

    vector<int> save(n, 0), vis(n,0);

    function<void(int, int)> dfs1;
    function<void(int,ll)> dfs2;

    dfs1 = [&](int cc, int estado){

        if(estado == cor[cc]) save[cc]++;
        vis[cc] = 1;

        for(auto [j,a]: graph[cc]){
            if(vis[j]) continue; 
            
            dfs1(j, estado);
            save[cc] += save[j];
        }
    };

    dfs2 = [&](int cc, ll sum){
        vis[cc] = 1;

        ll h = save[cc] + sum;

        for(auto [j,a]: graph[cc]){
            if(vis[j]) continue;
            
            ans[a] += (h-save[j]) * save[j];
            // save[cc] += save[j];
        }

        for(auto [j,a]: graph[cc]){
            if(vis[j]) continue;
            
            dfs2(j, h - save[j]);
        }
    };

    //------------------------   euler tour

    function<void(int)> solve2;

    solve2 = [&](int estado){

        int N = rel[estado].size();

        // fill(euler.begin(), euler.end(), 0);

        for(int ii = 0; ii < N; ii++){
            for(int jj = ii+1; jj < N; jj++){
                int i = rel[estado][ii], j = rel[estado][jj];

                int c = lca.lca(i, j);
                
                if(c == i || c == j){
                    int x;    
                    if(c == i) x = j;
                    else x = i;

                    euler[ver[c].first]++;
                    euler[ver[x].first]--;
                }
                else{
                    euler[ver[c].first]+=2;
                    euler[ver[i].first]--;
                    euler[ver[j].first]--;
                }
            }
        }

        // fill(euler.begin(), euler.end(), 0);
    };


    //------------------------

    for(int i = 0; i < n; i++){
        if(rel[i].size() >= magic){
            fill(vis.begin(), vis.end(), 0);
            fill(save.begin(), save.end(), 0);
            dfs1(0, i);
            fill(vis.begin(), vis.end(), 0);
            dfs2(0, 0);
        }

        else if(rel[i].size() > 0){
            solve2(i);
        }
    }

    ll sum = 0;
    for(ll &i: euler){
        sum += i;
        i = sum;
    }
    
    for(int i = 0; i < n-1; i++){
        ll h = euler[ar[i].first] - euler[ar[i].second];

        ans[i] += h;
    }


    for(int i = 0; i < n-1; i++) cout << ans[i] << " \n"[i == n-2];



    return 0;
}