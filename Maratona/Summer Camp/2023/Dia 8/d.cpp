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
#define pii pair<double,double>
#define pip pair<double, pii>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

using namespace std;

int main(){
    priority_queue<pip> pq1,pq2,pq3,pq4,pqmaster;
    int n; cin >> n;
    vector<pii> vecs(n);

    for(int i = 0; i < n; i++) {
        double a = 0;double b = 0;
        cin >> a >> b;
        double consta = (sqrt(a*a+b*b));
        if(consta != 0) {a/=consta;b/=consta;}
        vecs[i] = make_pair(a,b);
    }
    
    for(int i = 0; i < vecs.size(); i++){
        if (vecs[i].f >= 0 && vecs[i].s >= 0) pq1.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
        else if (vecs[i].f >= 0 && vecs[i].s < 0) pq2.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
        else if (vecs[i].f < 0 && vecs[i].s < 0) pq3.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
        else if (vecs[i].f < 0 && vecs[i].s >= 0) pq4.push(make_pair(vecs[i].f,make_pair(vecs[i].s, i)));
    }
    vector<vector<double> > xpyp(pq1.size()); vector<vector<double> > xpyn(pq2.size()); vector<vector<double> > xnyn(pq3.size()); vector<vector<double> > xnyp(pq4.size());

    for(int i = pq1.size()-1;i >= 0; i--) {pip a = pq1.top(); xpyp[i] = {a.f, a.s.f, a.s.s}; pq1.pop();}
    for(int i = 0;!pq2.empty(); i++) {pip a = pq2.top(); xpyn[i] = {a.f, a.s.f, a.s.s}; pq2.pop();}
    for(int i = pq3.size()-1;i >= 0; i--) {pip a = pq3.top(); xnyn[i] = {a.f, a.s.f, a.s.s};pq3.pop();}
    for(int i = 0;!pq4.empty() ; i++) {pip a = pq4.top(); xnyp[i] = {a.f, a.s.f, a.s.s};pq4.pop();}
    
    int pos=0;
    for(int i = 1; i < xpyp.size(); i++){
        pqmaster.push(make_pair(xpyp[i][0]*xpyp[i-1][0]+xpyp[i][1]*xpyp[i-1][1], make_pair(xpyp[i-1][2], xpyp[i][2])));
        // cout << xpyp[i-1][2] << es << xpyp[i][2] << endl;
    }
    for(int i = 1; i < xpyn.size(); i++){
        pqmaster.push(make_pair(xpyn[i][0]*xpyn[i-1][0]+xpyn[i][1]*xpyn[i-1][1],make_pair(xpyn[i-1][2], xpyn[i][2]))); //seg fa
    }
    for(int i = 1; i < xnyn.size(); i++){
        pqmaster.push(make_pair(xnyn[i][0]*xnyn[i-1][0]+xnyn[i][1]*xnyn[i-1][1],make_pair(xnyn[i-1][2], xnyn[i][2])));
    }
    for(int i = 1; i < xnyp.size(); i++){
        pqmaster.push(make_pair(xnyp[i][0]*xnyp[i-1][0]+xnyp[i][1]*xnyp[i-1][1],make_pair(xnyp[i-1][2], xnyp[i][2])));
    }

    int xpypt = xpyp.size() -1;
    int xpynt = xpyn.size()-1;
    int xnynt = xnyn.size()-1;
    int xnypt = xnyp.size()-1;

    if(xpyn.size()>0 && xpyp.size()>0)pqmaster.push(make_pair(xpyp[xpypt][0]* xpyn[0][0]+ xpyp[xpypt][1] * xpyn[0][1], make_pair(xpyp[xpypt][2], xpyn[0][2])));
    if(xpyn.size()>0 && xnyn.size()>0)pqmaster.push(make_pair(xpyn[xpynt][0]* xnyn[0][0]+ xpyn[xpynt][1]* xnyn[0][1], make_pair(xpyn[xpynt][2], xnyn[0][2])));
    if(xnyn.size()>0 && xnyp.size()>0)pqmaster.push(make_pair(xnyn[xnynt][0]* xnyp[0][0]+ xnyn[xnynt][1]* xnyp[0][1], make_pair(xnyn[xnynt][2], xnyp[0][2])));
    if(xnyp.size()>0 && xpyp.size()>0)pqmaster.push(make_pair(xnyp[xnypt][0]* xpyp[0][0]+ xnyp[xnypt][1]* xpyp[0][1], make_pair(xnyp[xnypt][2], xpyp[0][2])));

    if(xpyp.size()==1 && xnyn.size()==1)pqmaster.push(make_pair(xpyp[xpypt][0]* xnyn[0][0]+xpyp[xpypt][1]* xnyn[0][1], make_pair(xpyp[xpypt][2], xnyn[0][2])));
    
    if(xpyn.size()==1 && xnyp.size()==1)pqmaster.push(make_pair(xpyn[xpynt][0]* xnyp[0][0]+xpyn[xpynt][1]* xnyp[0][1], make_pair(xpyn[xpynt][2], xnyp[0][2])));

    cout << pqmaster.top().s.s+1 << es << pqmaster.top().s.f+1 << endl;
    
}