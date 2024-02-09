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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class flow_t, class cost_t> struct min_cost {
	static constexpr flow_t FLOW_EPS = flow_t(1e-10);
	static constexpr flow_t FLOW_INF = numeric_limits<flow_t>::max();
	static constexpr cost_t COST_EPS = cost_t(1e-10);
	static constexpr cost_t COST_INF = numeric_limits<cost_t>::max();
	int n, m{}; vector<int> ptr, nxt, zu;
	vector<flow_t> capa; vector<cost_t> cost;
	min_cost(int N) : n(N),ptr(n,-1),dist(n),vis(n),pari(n) {}
	void add_edge(int u, int v, flow_t w, cost_t c) {
		nxt.push_back(ptr[u]); zu.push_back(v); capa.push_back(w); cost.push_back(c); ptr[u] = m++;
		nxt.push_back(ptr[v]); zu.push_back(u); capa.push_back(0); cost.push_back(-c); ptr[v] = m++;
	}
	vector<cost_t> pot, dist; vector<bool> vis; vector<int> pari;
	vector<flow_t> flows; vector<cost_t> slopes;
	// You can pass t = -1 to find a shortest
	void shortest(int s, int t) {//path to each vertex. ///start-hash
		using E = pair<cost_t, int>;
		priority_queue<E, vector<E>, greater<E>> que;
		for(int u = 0; u < n; ++u){dist[u]=COST_INF; vis[u]=false;}
		for (que.emplace(dist[s] = 0, s); !que.empty(); ) {
			const cost_t c = que.top().first;
			const int u = que.top().second; que.pop();
			if (vis[u]) continue;
			vis[u] = true; if (u == t) return;
			for (int i = ptr[u]; ~i; i = nxt[i]) if (capa[i] > FLOW_EPS) {
				const int v = zu[i];
				const cost_t cc = c + cost[i] + pot[u] - pot[v];
				if(dist[v] > cc){que.emplace(dist[v]=cc,v);pari[v]=i;}
			}
		}
	}///end-hash
	auto run(int s, int t, flow_t limFlow = FLOW_INF) { ///start-hash
		pot.assign(n, 0); flows = {0}; slopes.clear();
		while (true) {
			bool upd = false;
			for (int i = 0; i < m; ++i) if (capa[i] > FLOW_EPS) {
				const int u = zu[i ^ 1], v = zu[i];
				const cost_t cc = pot[u] + cost[i];
				if(pot[v] > cc + COST_EPS) { pot[v] = cc; upd = true; }
			} if (!upd) break;
		}
		flow_t flow = 0; cost_t tot_cost = 0;
		while (flow < limFlow) {
			shortest(s, t); flow_t f = limFlow - flow;
			if (!vis[t]) break;
			for(int u = 0; u < n; ++u)pot[u] += min(dist[u],dist[t]);
			for (int v = t; v != s; ) { const int i = pari[v];
				if (f > capa[i]) { f = capa[i]; } v = zu[i^1];
			}
			for (int v = t; v != s; ) { const int i = pari[v];
				capa[i] -= f; capa[i^1] += f; v = zu[i^1];
			}
			flow += f; tot_cost += f * (pot[t] - pot[s]);
			flows.push_back(flow); slopes.push_back(pot[t] - pot[s]);
		} return make_pair(flow, tot_cost);
	} ///end-hash
}; 

signed solve(){

    int n,m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    min_cost<int,int> flow(2 + 3*m*n + 2*m + 2*n);

    const int pre = 3*m*n;
    const int fim = pre + 2*n + 2*m + 1;


    // 1 Ai = pre + i + 1
    // 0 Ai = pre + n + i + 1
    // 1 Bi = pre + 2*n + j + 1
    // 0 Bi = pre + 2*n + m + j + 1
    // t = pre + 2*n + 2*m + 1

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cc = m*i + j + 1;

            flow.add_edge(0, 2*m*n + cc, 2, 0);

            flow.add_edge(2*m*n + cc, cc, 2, (int)grid[i][j] != 1);
            flow.add_edge(2*m*n + cc, m*n + cc, 2, (int)grid[i][j] != 0);
            
            flow.add_edge(cc, pre + i + 1, 1, 0);
            flow.add_edge(cc, pre + 2*n + j + 1, 1, 0);

            flow.add_edge(m*n + cc, pre + n + i + 1, 1, 0);
            flow.add_edge(m*n + cc, pre + 2*n + m + j + 1, 1, 0);
        }
    }

    int s1 = 0, s2 = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s1 += x;
        flow.add_edge(pre + i + 1, fim, x, 0);
        flow.add_edge(pre + n + i + 1, fim, m-x, 0);
    }

    for(int j = 0; j < m; j++){
        int x; cin >> x;
        s2 += x;
        flow.add_edge(pre + 2*n + j + 1, fim, x, 0);
        flow.add_edge(pre + 2*n + m + j + 1, fim, n-x, 0);
    }

    pair<int,int> h = flow.run(0, fim);

    if(s1 != s2){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < flow.zu.size(); i+=2){
        int u = flow.zu[i], v = flow.zu[i^1], cap = flow.capa[i^1] + flow.capa[i], usado = flow.capa[i^1];
        if(  cap == 2  && (flow.capa[i^1] == 1)){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << h.second/2 << '\n';
    

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}