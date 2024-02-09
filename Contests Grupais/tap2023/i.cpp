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

typedef long long ll;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
using P = Point<double>;

double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int c,q,t; cin >> c >> q >> t;
    int n = c+q+t;

    vector<int> type(n, 0);
    vector<pair<int, P>> C(c);
    vector<vector<P>> Q(q), T(t);
    vector<vector<pair<int, double>>> graph(n);

    for(int i = 0; i < c; i++){
        type[i] = 1;
        for(int j = 0; j < 1; j++){
            int a,b,c; cin >> a >> b >> c;
            C[i] = {c, P(a,b) };
        }
    }

    for(int i = 0; i < q; i++){
        type[i+c] = 2;
        for(int j = 0; j < 2; j++){
            int a, b; cin >> a >> b;
            Q[i].push_back(P(a,b));
        }

        P mid = Q[i][1] - Q[i][0];

        mid.x/=2; mid.y/=2;

        P centro = Q[i][0] + mid;

        Q[i].push_back(centro + P( -mid.y, mid.x ));
        Q[i].push_back(centro + P( mid.y, -mid.x ));
    }

    for(int i = 0; i < t; i++){
        for(int j = 0; j < 3; j++){
            int a,b; cin >> a >> b;
            T[i].push_back(P(a,b));
        }
    }

    for(int i = 0; i < q; i++){
        for(int j = 0; j < t; j++){
            double dist = 1e16;
            
            for(int u = 0; u < 4; u++){
                for(int k = 0; k < 3; k++){
                    dist = min(dist, segDist(T[j][k], T[j][(k+1)%3], Q[i][u]));
                }
            }

            for(int u = 0; u < 4; u++){
                for(int v = u+1; v < 4; v++){
                    for(int k = 0; k < 3; k++){
                        dist = min(dist, segDist(Q[i][u], Q[i][v], T[j][k]));
                    }
                }
            }
            graph[c+i].push_back({c+q+j, dist});
            graph[c+q+j].push_back({c+i, dist});
        }
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < q; j++){

            double dist = 1e15;
            int r = C[i].first;

            for(int u = 0; u < 4; u++){
                for(int v = u+1; v < 4; v++){
                    double kk = segDist(Q[j][u], Q[j][v], C[i].second);
                    dist = min(dist, segDist(Q[j][u], Q[j][v], C[i].second) - r);
                }
            }

            graph[i].push_back({c+j, dist});
            graph[c+j].push_back({i, dist});
        }
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < t; j++){

            double dist = 1e15;
            int r = C[i].first;

            for(int u = 0; u < 3; u++){
                dist = min(dist, segDist(T[j][u], T[j][(u+1)%3], C[i].second) - r);
            }

            graph[i].push_back({c+q+j, dist});
            graph[c+q+j].push_back({i, dist});
        }
    }

    for(int i = 0; i < c; i++){
        for(int j = i+1; j < c; j++){
            graph[i].push_back({j, (C[i].second - C[j].second).dist() - C[i].first - C[j].first});
            graph[j].push_back({i, (C[i].second - C[j].second).dist() - C[i].first - C[j].first});
        }
    }

    vector<double> dist(n, 1e18);

    priority_queue<pair<double, int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;

    for(int i = c; i < c+q; i++){
        pq.push({0, i});
        dist[i] = 0;
    }

    while(!pq.empty()){
        auto[d, cc] = pq.top(); pq.pop();

        if(d < dist[cc]) continue;

        if(!type[cc]){
            cout << fixed << setprecision(15) << d << endl;
            return 0;
        }

        for(auto[j, cost]: graph[cc]){
            if(d + cost > dist[j]) continue;
            dist[j] = d + cost;
            pq.push({d+cost, j});
        }
    }

    return 0;
}