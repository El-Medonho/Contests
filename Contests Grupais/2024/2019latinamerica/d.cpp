#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;

template<class T> int sgn(T x) {return (x>0) - (x<0); }

template<class T> struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
    bool operator+(P p) const { return P(x+p.x, y+p.y); }
    bool operator-(P p) const { return P(x-p.x, y-p.y); }
    bool operator*(T d) const { return P(x*d, y*d); }
    bool operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return p.x*x - y*p.y; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y,x); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const { return P(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
};
using P = Point<int>;

vector<P> ch(vector<P> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.size()<=1) return v;

    vector<P> up,lw,cv;

    int n = (int)v.size();
    for(int i = 0; i < n; i++) {
        while(lw.size()>1 && v[i].cross(lw[lw.size()-2], lw[lw.size()-1])>=0) lw.pop_back();
        lw.push_back(v[i]);
    }
    for(int i=n-1; i>=0; i--) {
        while(up.size()>1 && v[i].cross(up[up.size()-2], up[up.size()-1])>=0) up.pop_back();
        up.push_back(v[i]);
    }
    lw.pop_back();
    up.pop_back();
    cv = up;
    for(P i:lw) cv.push_back(i);
    return cv;
}

struct Angle {
    int x, y;
    int t;
    A
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {

    }
    return 0;
}