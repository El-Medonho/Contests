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

bool cmpOrd(pair<ll, ll> x, pair<ll, ll> y){
    auto [a1, b1] = x;
    auto [a2, b2] = y;

    return b2*(a1-1) < b1*(a2-1);
}

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

struct line{
    ll m, c;
    line operator-(line l){
        return {m - l.m, c - l.c};
    }
    ll eval(ll x) { return m*x+c; }
    ll cross(line l) { return m*l.c - l.m*c; };
};

ll query(ll x, vector<line> &dq){
    int l=0, r = sz(dq)-1;
    while(l!=r){
        int mid = (l+r)>>1;
        if(dq[mid].eval(x)>=dq[mid+1].eval(x)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return dq[l].eval(x);
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

    sort(all(feit));

    vector<line> dq;

    for(auto [a, b]:feit){
        line cur;
        cur.m = a, cur.c = b;
        while(dq.size()>=2 && (cur - dq[sz(dq)-2]).cross(dq[sz(dq)-1] - dq[sz(dq)-2]) <= 0) dq.pop_back();
        dq.push_back(cur);
    }

    sort(all(ref), cmpOrd);

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
                    resp = query(resp, dq);

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