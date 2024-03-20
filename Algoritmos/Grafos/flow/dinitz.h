template<typename T = int> struct Dinitz {
	struct edge_t { int to, rev; T c, f; };
	vector<vector<edge_t>> adj;
	vector<int> lvl, ptr, q;
	Dinitz(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	inline void addEdge(int a, int b, T c, T rcap = 0) {
		adj[a].push_back({b, (int)adj[b].size(), c, 0});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, 0});
	}
	T dfs(int v, int t, T f) {///start-hash
		if (v == t || !f) return f;
		for (int &i = ptr[v]; i < int(adj[v].size()); ++i) {
			edge_t &e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (T p = dfs(e.to, t, min(f, e.c - e.f))) {
					e.f += p, adj[e.to][e.rev].f -= p;
					return p;
				}
		} return 0;
	}///end-hash
	T maxflow(int s, int t) {///start-hash
		T flow = 0; q[0] = s;
		for (int L = 0; L < 31; ++L) do { // consider L = 30
			lvl = ptr = vector<int>(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (edge_t &e : adj[v])
					if (!lvl[e.to] && (e.c - e.f) >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while(T p =dfs(s, t, numeric_limits<T>::max()/4))flow+=p;
		} while (lvl[t]);
		return flow;
	}///end-hash 
	bool leftOfMinCut(int v) { return bool(lvl[v] != 0); }
	auto minCut(int s, int t) {///start-hash
		T cost = maxflow(s,t); 
		vector<edge_t> cut;		
		for (int i = 0; i < int(adj.size()); i++) for(edge_t &e : adj[i])
			if (lvl[i] && !lvl[e.to]) cut.push_back(e);
		return make_pair(cost, cut);
	}///end-hash
};
struct flow_demand_t {///start-hash
	int N, src, sink;
	vector<int> d; Dinitz<int> flower;
	flow_demand_t(int N_):N(N_), src(N + 1), sink(N + 2), d(N + 3), flower(N + 3){}
	void add_edge(int a, int b, int demand, int cap) {
		d[a] -= demand; d[b] += demand;
		flower.addEdge(a, b, cap - demand);
	}
	int get_flow() {
		int x = 0, y = 0;
		flower.addEdge(N, N-1, numeric_limits<int>::max());
		for (int i = 0; i <= N; ++i) {
			if (d[i] < 0)
				flower.addEdge(i, sink, -d[i]), x += -d[i];
			if (d[i] > 0)
				flower.addEdge(src, i, d[i]), y += d[i];
		}
		bool has_circulation=(flower.maxflow(src,sink)==x && x==y);
		if (!has_circulation) return -1;
		return flower.maxflow(N-1, N);
	}
};///end-hash