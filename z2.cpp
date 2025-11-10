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

// achar o cara menor que zero mais a direita
// achar o cara igual a 0 com menor indice a direita desse malandro


struct Seg {
	vector<pair<ll,int>> tree; 
	vector<ll> lazy;
	int n = 1;

	Seg(int _n) : n(_n) {
		tree.resize(2*n, make_pair(0LL, 1e7)); lazy.resize(2*n, 0);
	}

	pair<ll,int> join(pair<ll,int> &a, pair<ll,int> &b) {
		if(a.first < b.first) {
			return a;
		} else if( b.first < a.first) return b;
		else {
			if(a.second < b.second) return a;
			return b;
		}
	}

	void unlazy(int node) {
		if(!lazy[node]) return;
		tree[node].first += lazy[node];
		if(node < n){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node]=0;
	}

	void upd(int node, int l, int r, int a, int b, ll val) {
		unlazy(node);
		if(a > r || b < l) return;
		if(l >= a && r <= b){
			lazy[node] += val;
			unlazy(node);
			return;
		}
		tree[node] = join(tree[2*node], tree[2*node+1]);
	}

	void upd_v(int node, int l, int r, int pos, int label) {
		if(l == r) tree[node].second = label;
		if(a > r || b < l) return;
		
		tree[node] = join(tree[2*node], tree[2*node+1]);
	}
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n; cin >> n;
	int N = n+n-1;
	vector<ll> arr(n);
	for(ll &i: arr) cin >> i;
	vector<vector<int>> graph(N);
	vector<int> pai(N, N-1);
	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b; a--; b--;
		graph[n-1+i].push_back(a); pai[a] = n-1+i;
		graph[n-1+i].push_back(b); pai[b] = n-1+i;
	}

    return 0;
}