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

#define endl '\n'

typedef long long ll;

struct Centroid {
	int n;
	vector<int> used, pai, sub;
	vector<int> order;
	vector<vector<int>> vec;

	Centroid(int n) : n(n), used(n+1), pai(n+1), sub(n+1), vec(n+1) {}

	void add_edge(int v, int u) {
		vec[v].push_back(u);
		vec[u].push_back(v);
	}

	int dfs_sz(int x, int p = 0) {
		sub[x] = 1;
		for(int i: vec[x]) {
			if(i == p || used[i]) continue;
			sub[x] += dfs_sz(i, x);
		}
		return sub[x];
	}

	int find_c(int x, int total, int p = 0) {
		for(int i: vec[x]) {
			if(i == p || used[i]) continue;
			if(2*sub[i] > total) return find_c(i, total, x);
		}
		return x;
	}

	void build(int x = 1, int p = 0) {
		int c = find_c(x, dfs_sz(x));

		order.push_back(c-1);

		used[c] = 1;
		pai[c] = p;
		for(int i: vec[c]) {
			if(!used[i]) build(i, c);
		}
	}

	vector<int> bb() {
		order.reserve(n);
		build();
		return order;
	}
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
	vector<vector<int>> graph(n);

	Centroid centroid(n);

	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		centroid.add_edge(a, b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> order = centroid.bb();
	vector<int> vis(n, 0);
	vector<pair<int,int>> ans(n, {n+5, n+5});
	int p = -1;

	auto dfs = [&](auto&&self, int cc, int last, int d, vector<set<int>> &v) -> void {
		while(v.size() <= d) v.push_back(set<int>());
		v[d].insert(cc);
		for(int j: graph[cc]){
			if(vis[j] || j == last) continue;
			self(self, j, cc, d+1, v);
		}
		return;
	};

	auto rdfs = [&](auto&&self, int cc, int last, int d, vector<set<int>> &v) -> void {
		while(v.size() <= d) v.push_back(set<int>());
		v[d].erase(cc);
		for(int j: graph[cc]){
			if(vis[j] || j == last) continue;
			self(self, j, cc, d+1, v);
		}
		return;
	};

	auto fdfs = [&](auto&&self, int cc, int last, int d, vector<set<int>> &v, map<int,int> &mp) -> void {
		if(mp.upper_bound(cc) != mp.end()) {
			int ind = (*mp.upper_bound(cc)).second;
	
			ans[cc] = min(ans[cc], make_pair(d + ind, (*v[ind].upper_bound(cc))));
		}

		for(int j: graph[cc]){
			if(vis[j] || j == last) continue;
			self(self, j, cc, d+1, v, mp);
		}
		return;
	};


	for(int x: order){
		vector<set<int>> v(1); v[0].insert(x);

		for(int j: graph[x]){
			if(vis[j]) continue;
			p = j;
			dfs(dfs, j, x, 1, v);
		}

		for(int i = 1; i < v.size(); i++){
			if(v[i].upper_bound(x) != v[i].end()) {
				ans[x] = min(ans[x], make_pair(i, (*v[i].upper_bound(x))));
			}
		}

		for(int j: graph[x]) {
			if(vis[j]) continue;
			rdfs(rdfs, j, x, 1, v);
			
			map<int,int> mp;
			int l = -1;
			for(int i = 0; i < v.size(); i++){
				if(v[i].size() == 0) break;
				int mx = (*v[i].rbegin());
				if(mx > l) {
					mp[mx] = i;
					l = mx;
				}
			}

			fdfs(fdfs, j, x, 1, v, mp);
			dfs(dfs, j, x, 1, v);
		}
		vis[x] = 1;
	}

	for(int i = 0; i < n; i++){
		cout << min(ans[i].second+1, n) << ' ';
	}
	cout << '\n';


    return 0;
}