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
typedef unsigned long long ull;

int main(){
    fastio;

    int n,k; cin >> n;
    vii arr(n);
    
    map<int,int> freq; set<int> nums;
    freq[0]++;
    nums.insert(0);

    ll sum = 0;
    for(int i = 0; i < n ; i++){
        int a; cin >> a;
        sum += a;
        sum = mod(sum, n);
        freq[sum]++;
        nums.insert(sum);
    }

    ll ans = 0;

    for(int x:nums){
        int hh = freq[x];
        for(int i = hh-1; i > 0; i--) ans += i;
    }

    cout << ans << endl;

    return 0;
}