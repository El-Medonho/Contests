#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef double ld;
const int mxn = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m,k; cin >> n >> m >> k;

    vector<vector<pair<int,int>>> graph(n);

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c; a--; b--;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }

    vector<ll> dist1(n, 1e18), dist2(n, 1e18);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.emplace(0LL, 0); dist1[0] = 0;

    while(!pq.empty()){
        auto[d, cc] = pq.top(); pq.pop();
        if(d > dist1[cc]) continue;

        for(auto[j, l]: graph[cc]){
            if(l+d < dist1[j]){
                pq.emplace(l+d, j);
                dist1[j] = l+d;
            }
        }
    }

    pq.emplace(0LL, n-1); dist2[n-1] = 0;
    
    while(!pq.empty()){
        auto[d, cc] = pq.top(); pq.pop();
        if(d > dist2[cc]) continue;

        for(auto[j, l]: graph[cc]){
            if(l+d < dist2[j]){
                pq.emplace(l+d, j);
                dist2[j] = l+d;
            }
        }
    }

    vector<pair<ll, ld>> order(0);
    bool ok = false;
    for(int i = 0; i < k; i++){
        int x; cin >> x; x--;
        ld c; cin >> c;
        if(abs(1-c) < 1e-9) ok = true;
        order.emplace_back(dist1[x]+dist2[x], c);
    }

    if(!ok){
        cout << "impossible\n";
        return 0;
    }

    sort(order.begin(), order.end());

    ld ans = 0, sum = 1;

    for(auto[cc, x]: order){
        ans += cc*x*sum;
        sum *=(1-x);
    }

    cout << fixed << setprecision(10) << ans << endl;


    return 0;
}