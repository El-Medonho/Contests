/**
 * Author: 
 * Date: 2021-02-19
 * License: 
 * Source: 
 * Status: stress-tested
 * Description: Data structure for computing lowest common ancestors and build Euler Tour in a tree.
 * Edges should be an adjacency list of the tree, either directed
 * or undirected.
 * Time: $O(N \log N + Q + Q \log)$
 */
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