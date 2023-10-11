#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 5e5+5;
const int mxm = 1e5+5;
const int MOD = 1e9+7;

int n, cont = -1;
ll ori[mxn];

template<typename T, typename Cmp=less<T>>
struct rmq_t : private Cmp {
int N = 0;
vector<vector<T>> table;
const T& min(const T& a, const T& b) const { return Cmp::
operator()(a, b) ? a : b; }
rmq_t() {}
rmq_t(const vector<T>& values) : N(int(values.size())), table
(__lg(N) + 1) {
table[0] = values;
for (int a = 1; a < int(table.size()); ++a) {
table[a].resize(N - (1 << a) + 1);
for (int b = 0; b + (1 << a) <= N; ++b)
table[a][b] = __gcd(table[a-1][b], table[a-1][b + (1 << (
a-1))]);
}
}
T query(int a, int b) const {
int lg = __lg(b - a);
return __gcd(table[lg][a], table[lg][b - (1 << lg) ]);
}
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    vector<ll> v(0);
    for(int i=1; i<=n; i++){
        cin >> ori[i];
    }
    for(int i=1; i<=n; i++){
        if(ori[i]==ori[i-1]) continue;
        v.push_back(ori[i]); cont++;
    }
    rmq_t<ll> Rmq(v);
    set<ll> sla;
    for(int i=0; i<=cont; i++){
        int l=i;
        
        while(l<=cont){
            int ini = l, fim = cont, meio, pos;
            
            ll pri = Rmq.query(i, ini+1);

            while(ini<=fim){
                meio = (ini+fim)>>1;
                if(Rmq.query(i, meio+1)<pri){
                    fim=meio-1;
                }else{
                    pos=meio;
                    ini=meio+1;
                }
            }
            
            l=pos+1;
            sla.insert(pri);
        }

    }
    cout << (int)sla.size() << endl;
    return 0;
}