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

int n,k; 
vii arr(0);


bool check(ll target){
    int curr = k-1;
    ll sum = 0;
    for(int &curri: arr){
        if(curri > target) return false;
        sum += curri;
        if(sum > target){
            curr--;
            if(curr < 0) return false;
            sum = curri;
        }
    }
    return true;
}

int main(){
    fastio;

    cin >> n >> k;

    arr.resize(n);
    for(int &x: arr) cin >> x;

    ll l = 0, r = 1e15;

    while(l < r){
        ll mid = (l+r)/2;
        bool doable = check(mid);
        if(!doable) l = mid+1;
        else r = mid;
    }
    
    ll mid = (l+r)/2;
    if(check(mid)) cout << mid << endl;
    else cout << mid+1 << endl;

    return 0;
}