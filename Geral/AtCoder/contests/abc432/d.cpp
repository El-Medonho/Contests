// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄


#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find
typedef pair<ll,ll> pii;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;
const ll inf = 1e18+5;

// ver se o retangulo ta na border
// se estiver, fazer dois retangulos
struct p {
    pii mn, mx;
    p() { mn = {0LL, 0LL}; mx = {0LL, 0LL};}
    p(pii m1, pii m2) : mx(m1), mn(m2) { }

    bool close(p other) {
        if(other.mn.first > this->mx.first+1 || other.mx.first+1 < this->mn.first || other.mn.second > this->mx.second+1 || other.mx.second+1 < this->mn.second || 
        (other.mn.first > this->mx.first && other.mx.second < this->mn.second) ||
        (other.mn.first > this->mx.first && other.mn.second > this->mx.second) ||
        (other.mx.first < this->mn.first && other.mn.second > this->mx.second) ||
        (other.mx.first < this->mn.first && other.mx.second < this->mn.second)
        ) return false;
        return true;
    }
};

signed solve(){
    
    int N; cin >> N;
    ll x,y; cin >> x >> y; x--; y--;

    vector<p> rect(0); rect.push_back(p({x,y},{0,0}));

    for(int i = 0; i < N; i++){
        int n = rect.size();
        vector<p> nrect(0);

        char c; cin >> c;
        ll a,b; cin >> a >> b;

        for(int i = 0; i < n; i++){
            p cc = rect[i];
            if(c == 'X'){
                if(cc.mn.first >= a || cc.mx.first < a) {
                    if(cc.mn.first >= a) {cc.mx.second += b; cc.mn.second += b;}
                    else {cc.mx.second -= b; cc.mn.second -= b;}
                    nrect.push_back(cc);
                    continue;
                }

                p c1 = cc, c2 = cc;

                c1.mx.first = a-1; c2.mn.first = a;
                
                c1.mx.second -= b; c1.mn.second -= b;
                c2.mx.second += b; c2.mn.second += b;

                nrect.push_back(c1); nrect.push_back(c2);
            }

            else{
                if(cc.mn.second >= a || cc.mx.second < a) {
                    if(cc.mn.second >= a) {cc.mx.first += b; cc.mn.first += b;}
                    else {cc.mx.first -= b; cc.mn.first -= b;}
                    nrect.push_back(cc);
                    continue;
                }

                p c1 = cc, c2 = cc;

                c1.mx.second = a-1; c2.mn.second = a;
                
                c1.mx.first -= b; c1.mn.first -= b;
                c2.mx.first += b; c2.mn.first += b;

                nrect.push_back(c1); nrect.push_back(c2);
            }
        }

        rect = nrect;
    }

    int n = rect.size();

    vector<int> pai(n, 0); vector<ll> peso(n, 0), w(n, 0);
    for(int i = 0; i < n; i++){
        pai[i] = i; peso[i] = 1;
        w[i] = (rect[i].mx.first - rect[i].mn.first+1) * (rect[i].mx.second - rect[i].mn.second+1);
    }

    function<int(int)> ff = [&](int x){
        if(x == pai[x]) return x;
        return pai[x] = ff(pai[x]);
    };

    function<void(int,int)> uu = [&](int a, int b){
        a = ff(a); b = ff(b);
        if(a == b) return;
        
        if(peso[a] < peso[b]) swap(a,b);

        peso[a] += peso[b]; w[a] += w[b];
        pai[b] = a;
    };

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(rect[i].close(rect[j])) uu(i, j);
        }
    }

    set<int> st;

    for(int i = 0; i < n; i++) st.insert(ff(i));

    vector<ll> ans(0);

    for(int x: st) ans.push_back(w[x]);

    sort(ans.begin(),ans.end());

    cout << ans.size() << endl;

    for(ll x: ans) cout << x << ' ';
    cout << endl;


    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}