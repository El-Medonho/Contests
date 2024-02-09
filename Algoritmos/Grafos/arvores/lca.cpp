#include "bits/stdc++.h"

using namespace std;

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