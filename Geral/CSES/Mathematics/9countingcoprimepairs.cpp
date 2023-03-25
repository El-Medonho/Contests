#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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

vii factors(int n){
    int k = 2;
    vii nums(0);
    while( k <= sqrt(n)){
        if(n % k == 0) nums.pb(k);

        while(n % k == 0) n/=k;
        k++;
    }
    if(n != 1) nums.pb(n);

    return nums;
}

int main(){
    fastio;

    ll n;
    vii arr(0);

    cin >> n;
    arr.resize(n);

    ll ans = (n*(n-1))/2;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<vii> pen(arr.back() + 1, vii(0));

    for(int i: arr){
        if(i == 1) continue;

        vii nums = factors(i);

        int sz = 1, gg = nums.size();
        while(gg > 0) {sz<<=1; gg--;}

        for(int j = 1; j < sz; j++){
            int op = 1, ind = 1;
            for(int k = 0; k < nums.size(); k++){
                if(j & (1<<k)){
                    op *= -1;
                    ind *= nums[k];
                }
            }

            ans += pen[ind].size() * op;
            pen[ind].pb(i);
        }
    }

    cout << ans << endl;

    return 0;
}