#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;
typedef double ld;

ld PI = acos(-1);
ld HQ = atan(1) * 2;


struct Point{
    ld x,y;

    Point(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}

    Point operator+ (Point p) const {return Point(x+p.x, y+p.y);}
    Point operator- (Point p) const {return Point(x-p.x, y-p.y);}
    Point operator* (ld d) const {return Point(x*d, y*d);}
    Point operator/ (ld d) const {return Point(x/d, y/d);}

    ld cross(Point p) const {return x*p.y - y*p.x;}
    ld cross(Point a, Point b) const {return (a-*this).cross(b-*this);}
    ld dist2() const {return x*x + y*y;}
    ld dist() const {return sqrt(x*x + y*y);}
    Point unit() const {return *this/dist();}
    Point perp() const {return Point(-y,x);}
};


ld dist(Point a, Point b){
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}

using P = Point;

template<class P>
ld lineDist(const P& a, const P& b, const P& p) {
    return (b-a).cross(p-a)/(b-a).dist();
}

template<class P>
P lineProj(P a, P b, P p, bool refl=false) {
    P v = b - a;
    return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();
}

vector<P> circleLine(P c, ld r, P a, P b) {
    ld h2 = r*r - a.cross(b,c)*a.cross(b,c)/(b-a).dist2();
    if (h2 < 0) return {};
    P p = lineProj(a, b, c), h = (b-a).unit() * sqrt(h2);
    if (h2 == 0) return {p};
    return {p - h, p + h};
}

int cmp_double(ld a, ld b = 0, ld eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

signed solve(){
    
    P p1, p2, c;

    int r;

    int a,b; cin >> a >> b;
    p1 = Point(a,b);

    cin >> a >> b;
    p2 = Point(a,b);

    cin >> a >> b;
    c = Point(a,b);

    cin >> r;

    vector<P> check = circleLine(c,r,p1,p2);

    if(check.size() != 0 || cmp_double(dist(p1, c), r) != 1 || cmp_double(dist(p2, c),r) != 1) {
        cout << fixed << setprecision(15) << dist(p1,p2) << endl;
        return 0;
    }

    function<ld(ld)>f;

    ld ini = 0;

    f = [&](ld num){
        num = num/90 * HQ;

        num += ini;

        Point cc(c.x + cos(num), c.y + sin(num));

        return dist(p1, cc) + dist(p2, cc);
    };

    function<ld(ld, ld)> ternary;

    ternary = [&](ld l, ld r){
        int cont=500;
        while(cont--){
            ld m1=l+(r-l)/3;
            ld m2=r-(r-l)/3;
            ld f1=f(m1);
            ld f2=f(m2);
            if(f1>f2){
                l=m1;
            }else{
                r=m2;
            }
        }
        return l;
    };

    ld ans1 = ternary(0, 180);

    ans1 = (f(ans1));

    ini = PI;

    ld ans2 = ternary(0, 180);

    ans2 = (f(ans2));

    cout << fixed << setprecision(15) << min(ans1, ans2) << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        solve();
    }

    return 0;
}