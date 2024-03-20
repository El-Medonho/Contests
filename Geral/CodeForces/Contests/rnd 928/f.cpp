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
			flow += f; 
            // tot_cost += f * (pot[t] - pot[s]);
            tot_cost += (pot[t] - pot[s]);
			flows.push_back(flow); slopes.push_back(pot[t] - pot[s]);
		} return make_pair(flow, tot_cost);
	} ///end-hash
}; 

signed solve(){

    int n = 7;

    int l = 0;

    vector<vector<int>> grid(n, vector<int>(n, 0)), nums(n, vector<int>(n, 0));

    vector<pair<int,int>> dir = {{1,1}, {-1,-1}, {-1,1}, {1,-1}};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            grid[i][j] += c == 'B';
        }
    }

    set<int> st;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            nums[i][j] += grid[i][j];

            for(auto [x,y]: dir){
                int ii = i+x, jj = j+y;
                if(ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                nums[i][j] += grid[ii][jj];
            }

            if(nums[i][j] == 5) {
                l++;
                st.insert(i*n+j);
                for(auto [x,y]: dir){
                    int ii = i+x, jj = j+y;
                    if(ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                    st.insert(ii*n+jj);
                }
            }
        }
    }

    if(l == 0){
        cout << 0 << endl;
        return 0;
    }

    int r = st.size();

    int s = 0, t = l+r+1;

    min_cost<int,int> flow(t+2);

    int cl = 1, cr = 0;

    map<int,int> mp;

    vector<pair<int,int>> edges(0);

    for(int i = 1; i <= l; i++) {
        flow.add_edge(0, i, 1, 0); 
        edges.push_back({0,i});
    }
    for(int i = l+1; i < t; i++) {
        flow.add_edge(i, t, 70, 1);
        edges.push_back({i,t});
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j] != 5) continue;

            if(mp[i*n+j] == 0) mp[i*n+j] = ++cr;
            flow.add_edge(cl, l+mp[i*n+j], 1, 0);
            edges.push_back({cl,l+mp[i*n+j]});

            for(auto [x,y]: dir){
                int ii = i+x, jj = j+y;
                if(ii < 0 || ii >= n || jj < 0 || jj >= n) continue;

                if(mp[ii*n+jj] == 0) mp[ii*n+jj] = ++cr;
                flow.add_edge(cl, l+mp[ii*n+jj], 1, 0);   
                edges.push_back({cl,l+mp[ii*n+jj]});             
            }           

            cl++;
        }
    }
    
    auto h = flow.run(s,t);

    cout << h.second << endl;

    return 0;
}

signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}