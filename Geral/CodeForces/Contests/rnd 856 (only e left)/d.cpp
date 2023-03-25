#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

ll expo(ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1) res = mod(res*b,MOD);
        b = mod(b*b,MOD);
        e>>=1;
    }
    return res;
}

int main(){
    fastio;

    int n; cin >> n; n*=2;
    vii arr(n);
    vii occur(1000006,0);

    vll fact(1e6*3, 1);
    for(int i = 1; i < 1e6*2; i++) fact[i] = mod(fact[i-1]*i,MOD);

    for(int &i:arr) cin >> i;

    set<int> primes,notprimes;

    for(int i = 0; i < n; i++){
        int curr = arr[i];

        bool pass = true;
        if(curr == 1) pass = false;
        for(int j = 2; j <= sqrt(double(curr)); j++){
            if(curr%j == 0){
                pass = false;
                break;
            }
        }

        occur[curr]++;

        if(pass){
            primes.insert(curr);
        }
        else{
            notprimes.insert(curr);
        }
    }

    if(primes.size() < n/2){
        cout << 0 << endl;
        return 0;
    }

    ll common = fact[n/2];
    ll den = 1;
    ll yy = n>>1;
    for(int x: notprimes){
        den = mod(den * fact[occur[x]], MOD);
        yy-=occur[x];
    }

    den = expo(den,MOD-2);
    common = mod(common*den,MOD);

    vii lista(0);
    for(int x: primes) lista.pb(x);

    vector<vll> dp(lista.size(), vll(yy+1,0));
    queue<int> qw;
    set<int> qw2;

    for(int i = 0; i < lista.size(); i++){
        int curr = lista[i];

        if(i == 0){
            dp[i][occur[curr]] = expo(fact[occur[curr]], MOD-2); qw.push(occur[curr]);
            dp[i][occur[curr]-1] = expo(fact[occur[curr]-1], MOD-2); qw.push(occur[curr]-1);
            continue;
        }

        while(!qw.empty()){
            int j = qw.front(); qw.pop();
            int tax = occur[curr];
            if(j + tax <= yy){
                qw2.insert(j+tax);
                dp[i][j+tax] += mod(dp[i-1][j] * expo(fact[tax],MOD-2), MOD);
                dp[i][j+tax] = mod(dp[i][j+tax],MOD);
            }
            tax--;
            if(j + tax <= yy){
                qw2.insert(j+tax);
                dp[i][j+tax] += mod(dp[i-1][j] * expo(fact[tax],MOD-2), MOD);
                dp[i][j+tax] = mod(dp[i][j+tax],MOD);
            }
        }
        for(int x:qw2){
            qw.push(x);
        }
        qw2.clear();
    }

    ll ans = dp[lista.size()-1][yy];

    cout << mod(ans*common,MOD) << endl;

    return 0;
}