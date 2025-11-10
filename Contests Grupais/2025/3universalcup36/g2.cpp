#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const double inf = 1/.0;

struct Line {
    mutable double k, m, p;
    int id;
    bool operator<(const Line &o) const {return k<o.k;}
    bool operator<(ll x) const {return p<x;};
};

struct LineContainer : multiset<Line, less<>>{
    double div(double a, double b){
        return a/b;
    }
    int issect(iterator x, iterator y){
        if(y == end()) { x->p = inf; return 0;}
        if(x->k==y->k) x->p=x->m > y->m?inf:-inf;
        else x->p=div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }

    void add(double k, double m, int id){
        auto z = insert({k, m, 0, id}), y = z++, x = y;
        while(issect(y, z)) z = erase(z);
        if(x!=begin() && issect(--x, y)) issect(x, y = erase(y));
        while((y=x) != begin() && (--x)->p >= y->p) issect(x, erase(y));
    }

    pair<double, pair<double, int> > query(double x){
        assert(!empty());
        auto l = *lower_bound(x);
        double resp = l.k*x + l.m;
        int id = l.id;
        erase(l);
        return make_pair(l.k, make_pair(resp, id));
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        int k; cin >> k;
    
        vector<ll> vals(n);
        
        int kk = k/n;
        
        kk -= 100;
    
        kk = max(kk, 0);

        k -= kk*n;
        
        vector<int> qtt(n, kk);
    
        for(int i = 0; i < n; i++) cin >> vals[i];
    
        sort(vals.begin(), vals.end());
    
        double ans = 1;

        LineContainer line;

        multiset<pair<double, int> > sla;

        for(int i = 0; i < n; i++){
            double cc = vals[i] * qtt[i];
            
            ans *= (1+cc/100);

            double sem = (1+cc/100);
            double mais1 = (1 + vals[i] * (qtt[i]+1.0)/100);

            sla.insert({mais1/sem, i});
        }


        for(int g = 0; g < k; g++){
            pair<double, int> best = {0, 0};

            auto it = sla.end();
            it--;

            auto [atual, id] = *it;

            ans *= atual;

            cout << atual << ' ' << ans << ' ' << id << endl;

            qtt[id]++;

            double cc = vals[id] * qtt[id];

            double sem = (1+cc/100);
            double mais1 = (1 + vals[id] * (qtt[id]+1)/100);

            sla.erase(it);

            sla.insert({mais1/sem, id});
        }
    
        cout << fixed << setprecision(10) << ans << endl;
        // for(int i: qtt) cout << i << ' ';
        // cout << endl;
    }




    return 0;
}