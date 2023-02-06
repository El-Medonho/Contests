#include <bits/stdc++.h>
#include <queue>

#define mxn 200005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define es " "
#define endl "\n"
#define pii pair<long double,long double>
#define pip pair<long double, pii>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

using namespace std;

long double sqrt_mod(long double a, int og){
    long double l = a, r = a+1;
    if(a*a > og){l--;r--;}
    int t = 300;
    while(t--){
        long double mid = (l+r)/2;
        if(mid*mid > og) r = mid;
        else l = mid;
    }
    return (l+r)/2;
}

int main(){
    fastio;
    priority_queue<pip> pq1,pq2,pq3,pq4,pqmaster;
    int n; cin >> n;
    vector<pii> vecs(n);

    for(int i = 0; i < n; i++) {
        long double a = 0;long double b = 0;
        cin >> a >> b;
        long double consta = (sqrtl(1.0*(a*a+b*b)));    //desgracado
        cout << consta << endl;
        consta = sqrt_mod(consta, a*a+b*b);
        if(consta != 0) {a/=consta;b/=consta;}
        // cout << sqrtl((long double)(99940010)) << endl;
        vecs[i] = make_pair(a,b);
    }
    
    for(int i = 0; i < vecs.size(); i++){
        if (vecs[i].f >= 0 && vecs[i].s >= 0) pq1.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
        else if (vecs[i].f >= 0 && vecs[i].s <= 0) pq2.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
        else if (vecs[i].f <= 0 && vecs[i].s <= 0) pq3.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
        else if (vecs[i].f <= 0 && vecs[i].s >= 0) pq4.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
    }
    vector<vector<long double> > xpyp(pq1.size()); vector<vector<long double> > xpyn(pq2.size()); vector<vector<long double> > xnyn(pq3.size()); vector<vector<long double> > xnyp(pq4.size());
    vector<vector<long double> > xkyk(pq1.size() + pq2.size() + pq3.size() + pq4.size());

    int cnt = 0;
    int alt = pq1.size()+cnt-1;
    for(int i = pq1.size()-1;i >= 0; i--) {  pip a = pq1.top(); xkyk[alt--] = {a.f, a.s.f, a.s.s}; pq1.pop(); cnt++;}

    for(int i = 0; !pq2.empty(); i++) {  pip a = pq2.top(); xkyk[cnt++] = {a.f, a.s.f, a.s.s}; pq2.pop();}
    
    for(int i = 0; !pq3.empty(); i++) { pip a = pq3.top(); xkyk[cnt++] = {a.f, a.s.f, a.s.s};pq3.pop();}
    alt = pq4.size()+cnt-1;
    for(int i = pq4.size()-1;i >= 0; i--) {  pip a = pq4.top(); xkyk[alt--] = {a.f, a.s.f, a.s.s};pq4.pop();}

    for(int i = 1; i < xkyk.size(); i++){
        pqmaster.push(make_pair(xkyk[i][0] * xkyk[i-1][0] + xkyk[i][1] * xkyk[i-1][1], make_pair(xkyk[i][2], xkyk[i-1][2])));
        cout << xkyk[i][0] << es << xkyk[i-1][0] << es << xkyk[i][1] << es << xkyk[i-1][1] << endl;
    }
    int last = xkyk.size()-1;
    pqmaster.push(make_pair(xkyk[0][0]*xkyk[last][0] + xkyk[0][1] * xkyk[last][1], make_pair(xkyk[last][2], xkyk[0][2])));

    cout << (pqmaster.top().s.s)+1 << es << (pqmaster.top().s.f)+1 << endl;
    
}