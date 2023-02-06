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

struct vt{
    ll x,y,id;
    vt(ll a = 0, ll b = 0, ll c = 0){x = a; y = b; id = c;}

    int quad(vt k){if(k.x >= 0 && k.y >= 0) return 1;
        else if(k.x < 0 && k.y >= 0) return 2;
        else if(k.x < 0 && k.y < 0) return 3;
        else return 4;
    }

    ll operator % (vt p) {return (*this).x * p.y - (*this).y * p.x;}
    ll operator * (vt p) {return (*this).x * p.x + (*this).y * p.y;}

    bool operator == (vt p) {return x == p.x && y == p.y;}

    bool operator < (vt p){
        int a = quad((*this)); int b = quad(p); 
        if(a!=b) return a < b;
        return (*this)%p > 0;
    }

    long double GetAngle(vt p){ long double t = atan2((*this)%p, (*this)*p); if(t < 0) t = abs(t) + acos(-1); return t;}
};

int main(){
    fastio;
    int n; cin >> n;
    vector<vt> vetores(n);
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        vetores[i] = vt(a,b,i+1);
    }
    sort(vetores.begin(), vetores.end());

    long double ans = 2*acos(-1); int id1,id2;
    for(int i = 0; i < n-1; i++){
        if(vetores[i].GetAngle(vetores[i+1]) < ans) {
            ans = vetores[i].GetAngle(vetores[i+1]);
            id1 = vetores[i].id; id2 = vetores[i+1].id;
        }
    }
    if(vetores[vetores.size()-1].GetAngle(vetores[0]) < ans){
        id1 = vetores[0].id; id2 = vetores[vetores.size()-1].id;
    }
    cout << id1 << es << id2 << endl;
}