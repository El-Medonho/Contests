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

void upd(int x, ll val, vll &bit){   //O(logn)
    while(x<=bit.size()-1){
        bit[x] = max(val, bit[x]);
        x+=x&-x;
    }
}
ll sum(int x, vll &bit){         //O(logn)
    ll ans=0;
    while(x){
        ans=max(ans,bit[x]);    
        x-=x&-x;    
    }
    return ans;
}

int main(){
    fastio;

    int n; cin >> n;
    vector<pair<pii, int>> arr(n);
    set<int> outtimes;

    for(pair<pii,int> &i: arr) {
        int a,b,c; cin >> a >> b >> c;
        outtimes.insert(b);
        i = {{b,a},c};
    }

    sort(arr.begin(), arr.end());

    int ggg = 1;
    map<int,int> cord;
    for(int x: outtimes){
        cord[x] = ggg++;
    }

    vll dp(outtimes.size()+1, 0);

    for(int i = 0; i < n; i++){
        pair<pii,int> curr = arr[i];
        auto x = lower_bound(arr.begin(), arr.end(),make_pair(make_pair(curr.f.s, 0), 0));
        if(x == arr.begin()) upd(cord[curr.f.f], curr.s, dp);
        else{
            x--;
            ll k = sum(cord[(*x).f.f], dp);
            upd(cord[curr.f.f], k+curr.s, dp);
        }
    }

    cout << sum(cord[*outtimes.rbegin()], dp) << endl;

    return 0;
}