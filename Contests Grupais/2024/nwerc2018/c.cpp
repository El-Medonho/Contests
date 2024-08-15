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
typedef double ld;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int d = 1e5;

// Returns -1 if a < b, 0 if a = b and 1 if a > b.
int cmp_double(double a, double b = 0, double eps = 1e-6) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

template<class T>
struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
};
typedef Point<ld> P ;

int lineInter(P s1, P e1, P s2, P e2) {
    if(e1 == s1) {
        if(e2 == s2) return e1 == e2;
        swap(s1, s2); swap(e1,e2);
    }
    P v1 = e1-s1, v2 = e2-s2, d = s2-s1;
    auto a = v1.cross(v2), a1 = d.cross(v1), a2 = d.cross(v2);
    if(cmp_double(a) == 0) {
        auto b1 = s1.dot(v1), c1 = e1.dot(v1), b2 = s2.dot(v1), c2 = e2.dot(v1);

        return !cmp_double(a1) && cmp_double(max(b1, min(b2,c2)), min(c1, max(b2,c2))) != 1;
    }
    if(cmp_double(a) < 0) {a = -a; a1 = -a1; a2 = -a2; }
    return (cmp_double(a1) != -1 && cmp_double(a1, a) < 1 && cmp_double(a2) != -1 && cmp_double(a2, a) < 1 );

}

ld dist(P a, P b) {
    P c = a-b;
    return (c.x*c.x + c.y*c.y);
}


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ld ag = acos(-1)/d;
    int n; cin >> n;

    uniform_int_distribution<int> uid(0, 1e5);

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int mx = 0;

    for(int i = 0; i < n; i++){
        if(graph[i].size() > graph[mx].size()) mx = i;
    }

    queue<int> qw; qw.push(mx);

    vector<int> vis(n, 0);
    vector<P> pos(n, P(0,0));
    vector<pair<int,int>> edges(0);

    vis[mx] = 1;

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();

        for(int j: graph[cc]){
            if(vis[j]) continue;

            vis[j] = 1;
            qw.push(j);

            bool ok = false;

            while(!ok){

                ok = true;

                int h = uid(rng);

                double v = ag * h;

                pos[j] = P(pos[cc].x + sin(v), pos[cc].y + cos(v));

                for(int i = 0; i < n; i++){
                    if(i == j) continue;
                    if(vis[i] && cmp_double(dist(pos[i], pos[j]),0,1e-2) == 0){
                        ok = false;
                        break;
                    }
                }

                if(!ok) continue;

                for(auto[a,b] : edges){
                    if(a == cc || a == j || b == cc || b == j) continue;

                    if(lineInter(pos[a], pos[b], pos[cc], pos[j])){
                        ok = false;
                        break;
                    }
                }
            }

            edges.push_back({cc, j});
        }
    }

    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(10) << pos[i].x;
        cout << ' ';
        cout << fixed << setprecision(10) << pos[i].y;
        cout << endl;
    }


    return 0;
}