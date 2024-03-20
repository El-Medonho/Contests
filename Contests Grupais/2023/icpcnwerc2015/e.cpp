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

using vi = vector<int>;
bool dfs(int a, int L, const vector<vi> &g, vi &btoa, vi &A, vi &B) { /// start-hash
	if (A[a] != L) return 0;
	A[a] = -1;
	for(auto &b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L+1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}
int hopcroftKarp(const vector<vi> &g, vi &btoa) { /// start-hash
	int res = 0;
	vector<int> A(g.size()), B(int(btoa.size())), cur, next;
	for (;;) {
		fill(A.begin(), A.end(), 0), fill(B.begin(), B.end(), 0);
		cur.clear();
		for(auto &a : btoa) if (a != -1) A[a] = -1;
		for (int a = 0; a < g.size(); ++a) if (A[a] == 0) cur.push_back(a);
		for (int lay = 1;; ++lay) { 
			bool islast = 0; next.clear();
			for(auto &a : cur) for(auto &b : g[a]) {
				if (btoa[b] == -1) B[b] = lay, islast = 1;
				else if (btoa[b] != a && !B[b]) 
					B[b] = lay, next.push_back(btoa[b]);
			}
			if (islast) break;
			if (next.empty()) return res;
			for(auto &a : next) A[a] = lay;
			cur.swap(next);
		}
		for(int a = 0; a < int(g.size()); ++a) 
			res += dfs(a, 0, g, btoa, A, B);
	}
} /// end-hash

signed main(){
    fastio;

    int n; cin >> n;
    vector<pair<ll,ll>> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    vector<vector<int>> graph(n);
    
    map<long long, long long> mp;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        set<ll> st;
        for(int j = 0; j < 3; j++){

            ll x = vector<ll> {arr[i].first + arr[i].second, arr[i].first - arr[i].second, arr[i].first * arr[i].second}[j];
            if(st.find(x) != st.end()) continue;
            st.insert(x);
            if(mp.find(x) == mp.end()){
                mp[x] = cnt++;
                graph.push_back({});
            }

            // graph[n+mp[x]].push_back(i);
            graph[i].push_back(n+mp[x]);
        }
    }

    vector<int> match(n+cnt, -1);

    int h = hopcroftKarp(graph, match);

    if(h < n){
        cout << "impossible\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){

            ll x = vector<ll> {arr[i].first + arr[i].second, arr[i].first - arr[i].second, arr[i].first * arr[i].second}[j];
            if(match[n+mp[x]] == i){
                cout << arr[i]. first << ' ' << "+-*"[j] << ' ' << arr[i].second << " = " << x << '\n';
                break;
            }
        }
    }

    return 0;
}