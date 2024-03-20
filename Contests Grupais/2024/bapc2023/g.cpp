#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn=3e2+5;
const int mxm=1e5+5;
const int MOD=1e9+7;
 
template<class T> struct Point{
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator==(P p) const {return tie(x, y)==tie(p.x, p.y);}
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    T cross(P p) const { return x*p.y - y*p.x; };
    T cross(P a, P b) const { return (a-*this).cross(b-*this);}
    T dist2() const {return x*x + y*y;}
};
using P = Point<ull>;
 
bool segmentIntersectionQ(P s1, P e1, P s2, P e2){
    if(e1==s1){
        if(e2==s2) return e1==e2;
        swap(s1, s2);
        swap(e1, e2);
    }
    P v1 = e1 - s1, v2 = e2-s2;
    auto a = v1.cross(v2);
    if(a==0) return 1;
    return 0;
}
 
void cases(){
    int n = 4;
    vector<P> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].x >> v[i].y;
    }
    int reto = 0;
    set<ull> sla;
    for(int i=0; i<n; i++){
        int j = (i+1)%n;
        int j2 = (i+2)%n;
        
        P a = P(v[i].x - v[j].x, v[i].y - v[j].y);
        P b = P(v[j].x - v[j2].x, v[j].y - v[j2].y);
 
        if(a.x*b.x + a.y*b.y == 0) reto++;
 
        sla.insert(a.dist2());
    }
    if(reto==4 && sz(sla)==1){
        cout << "square" << endl;
    }else if(reto==4){
        cout << "rectangle" << endl;
    }else if(sz(sla)==1){
        cout << "rhombus" << endl;
    }else{
        int ans = segmentIntersectionQ(v[0], v[1], v[3], v[2]);
        ans += segmentIntersectionQ(v[1], v[2], v[0], v[3]);
 
        if(ans==2){
            cout << "parallelogram" << endl;
        }else if(ans==1){
            cout << "trapezium" << endl;
        }else{
            P a = P(v[0].x - v[1].x, v[0].y-v[1].y);
            P b = P(v[1].x - v[2].x, v[1].y-v[2].y);
            P c = P(v[2].x - v[3].x, v[2].y-v[3].y);
            P d = P(v[3].x - v[0].x, v[3].y-v[0].y);
 
            if((a.dist2() == b.dist2() && c.dist2() == d.dist2()) != (b.dist2() == c.dist2() && a.dist2() == d.dist2())){
                cout << "kite" << endl;
            }else{
                cout << "none" << endl;
            }
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t=1;
 
    // cin >> t;
 
    for(int i=1; i<=t; i++){
        // cout << "Case #" << i << ": ";
        cases();
    }
    return 0;
}