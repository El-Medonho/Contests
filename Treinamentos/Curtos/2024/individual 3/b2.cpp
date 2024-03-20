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
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

struct line{
    int xi,yi,xf,yf;
    line(int _xi = 0, int _yi = 0, int _xf = 0, int _yf = 0) : xi(_xi), yi(_yi), xf(_xf), yf(_yf) {}
};

struct bm_t {
	int N, M, T;
	vector<vector<int>> adj;
	vector<int> match, seen;
	bm_t(int a, int b) : N(a), M(a+b), T(0), adj(M),
	match(M, -1), seen(M, -1) {}
	void add_edge(int a, int b) { adj[a].push_back(b+N); }
	bool dfs(int cur) {
		if (seen[cur] == T) return false;
		seen[cur] = T;
		for (int nxt : adj[cur]) if (match[nxt] == -1) {
			match[nxt] = cur, match[cur] = nxt;
			return true;
		}
		for (int nxt : adj[cur]) if (dfs(match[nxt])) {
			match[nxt] = cur, match[cur] = nxt;
			return true;
		}
		return false;
	}
	int solve() {
		int res = 0;
		for (int cur = 1; cur; ) {
			cur = 0; ++T;
			for (int i = 0; i < N; ++i) if (match[i] == -1)
				cur += dfs(i);
			res += cur;
		}
		return res;
	}
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    const int sz = 255;

    vector<line> arr(n), l, r(0);

    for(int i = 0; i < n; i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        if(a > c) swap(a,c);
        if(b > d) swap(b,d);
        arr[i] = line(a,b,c,d);
    }

    vector<vector<int>> graph(n);

    int a = 0, b = 0;

    for(int i = 0; i < n; i++){
        if(arr[i].xi == arr[i].xf) b++;
        else {a++; l.push_back(arr[i]);}
    }

    for(int i = 0; i < n; i++){
        if(arr[i].xi == arr[i].xf) r.push_back(arr[i]);
    }

    bm_t match(a,b);

    for(int i = 0; i < l.size(); i++){
        for(int j = 0; j < r.size(); j++){

            if( (l[i].xi <= r[j].xi && l[i].xf >= r[j].xi) && (r[j].yi <= l[i].yi && r[j].yf >= l[i].yi) ){
                // graph[i].push_back(j);
                match.add_edge(i,j);
            }
        }
    }

    int mf = match.solve();

    cout << n-mf << endl;

    return 0;
}