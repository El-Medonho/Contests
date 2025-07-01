#include <bits/stdc++.h>
 
using namespace std;

#define f first
#define s second
#define pb push_back
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 3e2+5;
const int mxm = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// Returns -1 if a < b, 0 if a = b and 1 if a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y){
    auto [a1, b1] = x;
    auto [a2, b2] = y;

    return b2*(a1-1) < b1*(a2-1);
}

//acha o maior valor de y para um determinado x, para retas da forma ax + b que estão na estrutura
struct Line{
    mutable ll k, m, p;
    bool operator<(const Line& o) const {return k<o.k;}
    bool operator<(ll x) const {return p<x;}
};

struct LineContainer : multiset<Line, less<>>{
    // for doubles: use inf = 1/.0, div(a, b) = a/b

    ll div(ll a, ll b){
        return a/b-((a^b)<0 && a%b);
    }

    int issect(iterator x, iterator y){
        if(y==end()) {x->p=INFL; return 0;}
        if(x->k==y->k) x->p=x->m > y->m?INFL:-INFL;
        else x->p=div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    
    //para achar o mínimo, é preciso fazer insert({-k, -m, 0}), além disso multiplicar por -1 o resultado da query
    void add(ll k, ll m){
        auto z=insert({k, m, 0}), y=z++, x=y;
        while(issect(y, z)) z=erase(z);
        if(x!=begin() && issect(--x, y)) issect(x, y=erase(y));
        while((y=x) != begin() && (--x)->p >= y->p) issect(x, erase(y));
    }
    
    ll query(ll x){
        assert(!empty());
        auto l=*lower_bound(x);
        return l.k*x+l.m;
    }
};

auto efeito(pair<ll, ll> x, pair<ll, ll> y){
    auto [a1, b1] = x;
    auto [a2, b2] = y;

    pair<ll, ll> resp;

    resp.f = (a1 * a2)%MOD;
    resp.s = ((a1 * b2)%MOD + b1)%MOD;

    return resp;
}

auto exp(pair<int, int> x, int e){
    pair<ll, ll> resp = {1, 0};
    while(e){
        if(e&1) resp = efeito(resp, x);
        x = efeito(x, x);
        e>>=1;
    }
    return resp;
}


signed cases(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<ll, ll> > feit(n), ref(m);

    for(int i=0; i<n; i++){
        cin >> feit[i].f;
    }
    for(int i=0; i<n; i++){
        cin >> feit[i].s;
    }

    pair<ll, ll> best = {0, 0};
    for(int i=0; i<n; i++){
        best = max(best, feit[i]);
    }

    for(int i=0; i<m; i++){
        cin >> ref[i].f;
    }
    for(int i=0; i<m; i++){
        cin >> ref[i].s;
    }

    LineContainer ln;

    for(auto [a, b]:feit){
        ln.add(a, b);
    }

    sort(all(ref), cmp);

    pair<ll, ll> refOrd = {1, 0};

    for(auto i:ref){
        refOrd = efeito(i, refOrd);
    }

    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;

        ll resp = x;
        if(best.f == 1){
            resp = (x + (best.s*k)%MOD)%MOD;
        }else{
            int acabou = 0;
            for(int i=0; i<k; i++){
                if(acabou){
                    auto agr = exp(best, k-i);

                    resp = ((agr.f*resp)%MOD + agr.s)%MOD;
                    
                    break;
                }else{
                    resp = ln.query(resp);

                    if(resp>=MOD){
                        resp%=MOD, acabou = 1;
                    }
                }
            }
        }
        resp = ((refOrd.f * resp)%MOD + refOrd.s)%MOD;
        cout << resp << endl;
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t=1;

    //cin >> t;

    for(int i=1; i<=t; i++){
        //cout << "Case #" << i << ": ";
        cases();
    }
    return 0;
}