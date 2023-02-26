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

    map<int,int, greater<int>> mp;
    int n,m; cin >> n >> m; 
    vii arr(m);
    for(int i = 0; i < n; i++) {int a; cin >> a; mp[a]++;}
    for(int i = 0; i < m; i++) cin >> arr[i];

    for(int x: arr){
        auto k = mp.lower_bound(x);
        if(k == mp.end()) {cout << -1 << endl; continue;}
        cout << (*k).f << endl;
        mp[(*k).f]--;
        if(mp[(*k).f] == 0) mp.erase(k);
    }

    return 0;
}