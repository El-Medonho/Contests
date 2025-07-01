#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double ld;

#define endl '\n'

template<class T> struct Point {
    typedef Point P;
    T x,y;
    explicit Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) { }
    P operator+ (P p) const {return P(x+p.x, y+p.y);}
    P operator- (P p) const {return P(x-p.x, y-p.y);} 
    P operator* (T d) const {return P(x*d, y*d);}
    T dist2() const { return x*x + y*y;}
    T dot(P p) const {return x*p.x + y*p.y; }
    P perp() const {return P(-y, x);}
};

using P = Point<ld>;

bool circleInter(P a, P b, ld r1, ld r2, pair<P, P>* out) {
    // if(a == b) { assert(r1 != r2); return false; }
    P vec = b-a;
    ld d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
    p = (d2+r1*r1-r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
    if(sum * sum < d2 || dif*dif > d2) return false;
    P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2)/d2);
    *out = {mid+per, mid-per};
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> graph(n), matrix(n, vector<int>(n, 0));

    vector<pair<P,int>> arr(n, make_pair(P(0,0), 0));

    for(int i = 0; i < n; i++){
        int x,y,r; cin >> x >> y >> r;
        arr[i] = pair<P,int>(P(x,y), r);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            pair<P,P> ini;
            if(circleInter(arr[i].first, arr[j].first, arr[i].second, arr[j].second, &ini)){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<int> ban(n, 0);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ld d = sqrt((arr[i].first - arr[j].first).dist2());
            if(d + arr[i].second < arr[j].second) ban[i] = 1;
        }
    }

    vector<int> low(n, -1), id(n, -1), pai(n, -1);
    stack<int> stk;
    int t = 0;

    auto dfs = [&](auto&& self, int cc, int last) -> void {
        id[cc] = low[cc] = t++;
        stk.push(cc);
        for(int nxt: graph[cc]){
            if(ban[nxt]) continue;
            if(id[nxt] == -1){
                self(self,nxt, cc);
                low[cc] = min(low[cc], low[nxt]);
                if(low[nxt] > id[cc]){
                    matrix[nxt][cc] = matrix[cc][nxt] = -1;
                }
            }
            else if(nxt != last){
                low[cc] = min(low[cc], id[nxt]);
            }
        }

        if(low[cc] == id[cc]){
            int u = -1;
            do{
                u = stk.top(); stk.pop();
                pai[u] = cc;
            }
            while(u != cc);
        }
    };

    for(int i = 0; i < n; i++){
        if(id[i] == -1 && !ban[i]) dfs(dfs, i, -1);
    }

    for(int i = 0; i < n; i++){
        if(ban[i]) continue;
        for(int j: graph[i]){
            if(pai[i] != pai[j] || matrix[i][j] == -1 || ban[j]) continue;
            matrix[i][j] = matrix[j][i] = 1;
        }
    }



    for(int i = 0; i < n; i++){
        if(ban[i]) continue;
        for(int j: graph[i]){
            if(pai[i] != pai[j] || ban[j]) continue;
            bool ok = false;
            pair<P,P> edges;
            circleInter(arr[i].first, arr[j].first, arr[i].second, arr[j].second, &edges);
            pair<int,int> estado = {-1,-1};

            for(int k: graph[i]){
                if(k == j || matrix[k][j] == 0 || ban[k]) continue;
                ok = true;

                ld d1 = (arr[k].first-edges.first).dist2(), d2 = (arr[k].first-edges.second).dist2(), db = (edges.first-edges.second).dist2();

                if(d1 < d2 && (edges.second-edges.first).dot(arr[k].first-edges.first) < 0) estado.first = max(estado.first, 0);
                if(d2 < d1 && (edges.first-edges.second).dot(arr[k].first-edges.second) < 0) estado.second = max(estado.second, 0);

                if(sqrt(d1) < arr[k].second) estado.first = 1;
                if(sqrt(d2) < arr[k].second) estado.second = 1;
            }

            if(!ok || estado.first == 0 || estado.second == 0){
                cout << 1 << '\n';
                return 0;
            }
        }
    }

    cout << 0 << '\n';

    return 0;
}