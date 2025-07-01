#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const ll mod = 998244353;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    int m = 25;

    vector<array<ll,25>> a(n), imp(n), par(n), o(n), tot(n);

    ll A = 0, X = 0, O = 0;

    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    vector<vector<int>> graph(n);

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    function<void(int,int)> dfs;

    dfs = [&](int cc, int last){
        for(int j: graph[cc]){
            if(j == last) continue;
            dfs(j, cc);
        }

        for(int i = 0; i < m; i++){

            ll mult = (1LL<<i) * (1LL<<i);
            mult %= mod;

            ll sum = 0;

            if(arr[cc] & (1<<i)){
                for(int j: graph[cc]){  // compute AND
                    if(j == last) continue;

                    sum += a[j][i];
                }

                a[cc][i] = sum;

                A += 2*sum * mult % mod;
                if(A >= mod) A -= mod;

                for(int j: graph[cc]){
                    if(j == last) continue;
                    
                    A += a[cc][i] * (sum - a[cc][i]) % mod  * mult % mod;
                    if(A >= mod) A -= mod;
                }
            }

            ll even = 0, odd = 0;

            for(int j: graph[cc]){  // compute XOR
                if(j == last) continue;
                even += par[j][i];
                odd += imp[j][i];
            }

            par[cc][i] = even;
            imp[cc][i] = odd;

            if(arr[cc] & (1<<i)){
                X += 2*even * mult % mod;
                if(X >= mod) X -= mod;

                for(int j: graph[cc]){
                    if(j == last) continue;

                    X += par[j][i] * (even - par[j][i]) % mod  * mult % mod;
                    if(X >= mod) X -= mod;

                    X += imp[j][i] * (odd - imp[j][i]) % mod  * mult % mod;
                    if(X >= mod) X -= mod;
                }
            }
            else{
                X += 2*odd * mult % mod;
                if(X >= mod) X -= mod;
                for(int j: graph[cc]){
                    if(j == last) continue;

                    X += imp[j][i] * (even - par[j][i]) % mod  * mult % mod;
                    if(X >= mod) X -= mod;

                    X += par[j][i] * (odd - imp[j][i]) % mod  * mult % mod;
                    if(X >= mod) X -= mod;
                }
            }

            sum = 0;
            ll total = 0;

            for(int j: graph[cc]){  // compute OR
                if(j == last) continue;

                sum += o[j][i];
                total += tot[j][i];
            }

            if(arr[cc] & (1<<i)) O += 2*total  * mult % mod;
            else O += 2*sum  * mult % mod;

            if(O >= mod) O -= mod;

            tot[cc][i] = total + 1;
            o[cc][i] = sum;

            for(int j: graph[cc]){
                if(j == last) continue;

                O += o[j][i] * (total - tot[j][i]) % mod;
                if(O >= mod) O -= mod;

                O += (tot[j][i] - o[j][i]) * (sum) % mod;
                if(O >= mod) O -= mod;
            }


            if(arr[cc] & (1<<i)){
                o[cc][i]++;
                a[cc][i]++;
                swap(imp[cc][i], par[cc][i]);
                imp[cc][i]++;

                A += mult;
                if(A >= mod) A -= mod;
            }
            else{
                a[cc][i] = 0;
                par[cc][i]++;
            }
        }
    };

    dfs(0,0);

    cout << A << ' ' << X << ' ' << O << endl;

    return 0;
}