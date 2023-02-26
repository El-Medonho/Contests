#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
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

int main(){
    fastio;

    int t; cin >> t;
    while(t--){
        ll n,c;
        cin >> n >> c;

        vll arr(n);
        vector<pll> arrbest(n);
        vll arrsum(n);
        set<pll> setsum;
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            arrbest[i] = {min(arr[i]+i+1, arr[i]+n-i),i};
        }
        sort(arrbest.begin(), arrbest.end());

        for(int i = 0; i < n; i++){
            sum += arrbest[i].f;
            arrsum[arrbest[i].s] = sum; 
            setsum.insert({sum, i});
        }
        ll best = 0;
        for(int i = 0; i < n; i++){
            ll ans = 0;
            ll search = c;
            ll begin = (arr[arrbest[i].s]+arrbest[i].s+1);
            if(begin > c) continue;
            ll consta =  (arr[arrbest[i].s]+arrbest[i].s+1)-arrbest[i].f;

            if(c >= arrsum[arrbest[i].s] + consta) search -= consta;
            else{
                ans++;
                search-=begin;
            }

            auto x = setsum.upper_bound({search,INF});
            if(x == setsum.end()) ans = n;
            else {
                pll k = *x; 
                ans += k.s;
            }
            best = max(best, ans);
        }
        cout << best << endl;
    }

    return 0;
}